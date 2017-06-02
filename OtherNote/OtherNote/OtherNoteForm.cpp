//OtherNoteForm.cpp

#include "OtherNoteForm.h"
#include "Memo.h"
#include "Line.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
#include "CharacterFaces.h"
#include "MakeStringVisitor.h"
#include "Caret.h"
#include <WinUser.h>
#include <fstream>
using namespace std;

BEGIN_MESSAGE_MAP(OtherNoteForm, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_CHAR()
	ON_MESSAGE(WM_IME_COMPOSITION, OnImeComposition)
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

OtherNoteForm::OtherNoteForm() {

}

BOOL OtherNoteForm::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CFrameWnd::OnCreate(lpCreateStruct);
	
	this->memo = new Memo;
	
	CPaintDC dc(this);
	CharacterFaces *characterFaces = CharacterFaces::Instance(&dc);
	
	//this->Load();
	
	Caret *caret = Caret::Instance(this);
	
	this->endComposition = true;
	
	this->RedrawWindow();

	return FALSE;
}

void OtherNoteForm::OnClose() {
	Caret *caret = Caret::Instance(this);
	if (caret != 0) {
		delete caret;
	}

	//this->Save();

	CharacterFaces *characterFaces = CharacterFaces::Instance(0);
	if (characterFaces != 0) {
		delete characterFaces;
	}

	if (this->memo != 0) {
		delete this->memo;
	}

	CFrameWnd::OnClose();
}

#include "PaintVisitor.h"
#include "ArrayIterator.h"

void OtherNoteForm::OnPaint() {
	CPaintDC dc(this);
	//CRect rect = { 0,0,2000,2000 };
	CRect rect;
	GetClientRect(&rect);
	PaintVisitor paintVisitor(&dc, &rect);
	
	this->memo->Accept(&paintVisitor);
}


void OtherNoteForm::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {
	if (nChar >= 32 && nChar <= 126) {
		Line *line = this->memo->GetLine(this->memo->GetRow());
		line->Write(nChar);

		Caret *caret = Caret::Instance(this);
		caret->MoveNextCharacter();

	}
	this->RedrawWindow();

}

LRESULT OtherNoteForm::OnImeComposition(WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(wParam);
	UNREFERENCED_PARAMETER(lParam);

	char composition[2];
	composition[0] = HIBYTE(wParam);
	composition[1] = LOBYTE(wParam);
	//composition[0] = *(((char*)&wParam) + 1);
	//composition[1] = *((char*)&wParam);

	Line *lineLink = this->memo->GetLine(this->memo->GetRow());

	Caret *caret = Caret::Instance(0);
	caret->ChangeImeCaret();
	
	if (lParam & GCS_COMPSTR) {

		if (this->endComposition == false) {
			lineLink->Erase();
		}
		this->endComposition = false;

		if (!(composition[1] == '\x1b' && composition[0] == '\0')) {
			lineLink->Write(composition);
		}
		else {
			this->endComposition = true;
		}
	}
	if (lParam & GCS_RESULTSTR) {
		this->endComposition = true;
		lineLink->Erase();
		lineLink->Write(composition);
		caret->MoveNextCharacter();
		caret->ChangeCaret();
	}

	this->RedrawWindow();

	return 0;
}

#include "KeyActionCreator.h"
#include "KeyAction.h"
void OtherNoteForm::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
		KeyActionCreator keyActionCreator;
		KeyAction *keyAction = keyActionCreator.Create(this, nChar, nRepCnt, nFlags);
		if (keyAction != 0) {
			keyAction->OnKeyDown(nChar, nRepCnt, nFlags);
			delete keyAction;
			keyAction = 0;
		}	
}
#include "Mouse.h"
void OtherNoteForm::OnMouseMove(UINT nFlags, CPoint point) {
	//UNREFERENCED_PARAMETER(nFlags);
	//UNREFERENCED_PARAMETER(point);
	
	Mouse mouse(this);
	mouse.OnMouseMove(nFlags, point);

}

void OtherNoteForm::OnLButtonDown(UINT nFlags, CPoint point) {
	Mouse mouse(this);
	mouse.OnLButtonDown(nFlags, point);
	
}

void OtherNoteForm::OnLButtonUp(UINT nFlags, CPoint point) {
	//CRect rect(20, 20, 210, 210);
	//Invalidate();
	//this->UpdateWindow();

}

/*
void OtherNoteForm::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Line *line = this->memo->GetLine(this->memo->GetRow());
	Caret *caret = Caret::Instance(this);

	//row를 public이든, noteBookForm에서 멤버로 하나 가지고 있든
	Long row = this->memo->GetRow();
	Long column = line->GetColumn();
	//
	
	if (nChar == VK_LEFT) {
		if (column > 0) {
			caret->MovePreviousCharacter();
			line->MoveLeftColumn();
		}
	}

	else if (nChar == VK_UP) {
		if (row > 0) {
			Long originalXPosition = caret->GetXPosition();

			caret->MovePreviousLine();
			this->memo->MoveUpRow();

			line = this->memo->GetLine(this->memo->GetRow());
			
			//column = 0;
			line->SetColumn(0);
			Long previousWidth=-1;
			Long currentWidth = 0;
			while (currentWidth < originalXPosition && line->GetColumn()<line->GetLength()) {
				previousWidth = currentWidth;
				currentWidth+=line->GetCharacter(line->GetColumn())->GetWidth();
				line->MoveRightColumn();
			}

			Long resultWidth;
			if (currentWidth - originalXPosition < originalXPosition - previousWidth) {
				resultWidth = currentWidth;
			}
			else {
				resultWidth = previousWidth;
			}

			caret->Move(resultWidth, caret->GetYPosition());
			//Long totalWidth = 0;
			//column = 0;
			//Long i = 0;
			//Character *character = line->GetCharacter(column);
			//while(column<line->GetLength() && )

			//line = this->memo->GetLine(this->memo->GetRow());
			//Long totalWidth = 0;
			//Long i = 0;
			//while (i < line->GetLength()) {
			//	Character *character = line->GetCharacter(i);
			//	totalWidth += character->GetWidth();
			//	i++;
			//}

			//Long xPosition = 0;
			//if (xPosition > totalWidth) {
			//	xPosition = totalWidth;
			//}
			//else {

			//}
		}
	}

	else if (nChar == VK_DOWN) {
		this->memo->MoveDownRow();
		caret->MoveNextLine();
	}

	else if (nChar == VK_RIGHT) {
		if (column < line->GetLength()) {
			line->MoveRightColumn();
			caret->MoveNextCharacter();
		}
	}
	else if (nChar == VK_BACK) {
		if (line->GetLength() != 0) {
			line->Erase();
		}
		else if (this->memo->GetRow() != 0 && line->GetLength() == 0) {
			if (this->memo->GetLength() != 1) {
				this->memo->RemoveLine(this->memo->GetLength() - 1);
				Line *currentLineLink = this->memo->GetLine(this->memo->GetLength() - 1);
				currentLineLink->SetColumn(currentLineLink->GetLength());
			}
		}
	}
}

void OtherNoteForm::Load() {
	fstream fs("aha.txt", ios::in);
	if(!fs.fail()) {
		char buffer[10000];
		fs.getline(buffer, sizeof(buffer));
		CharacterFaces *characterFaces = CharacterFaces::Instance(0);
		characterFaces->SetFontFamily(buffer);
		fs.getline(buffer, sizeof(buffer));
		string temp(buffer);
		Long fontSize = stoi(temp);
		characterFaces->SetFontSize(fontSize);
		Line *line;
		char doubleCharacter[2];
		Long j = 0;
		fs.getline(buffer, sizeof(buffer));
		while(!fs.eof()) {
			line = this->memo->GetLine(j);
			Long length = string(buffer).length();
			Long i = 0;
			while(i < length-1) {
				if(buffer[i] >= 0 && buffer[i] <= 127){
					line->Write(buffer[i]);
				}
				else {
					doubleCharacter[0] = buffer[i];
					doubleCharacter[1] = buffer[i+1];
					i++;
					line->Write(doubleCharacter);
				}
				i++;
			}
			this->memo->AddLine();
			j++;
			fs.getline(buffer, sizeof(buffer));
		}
		this->memo->RemoveLine(this->memo->GetLength()-1);
		fs.close();
	}
	this->memo->SetRow(0);
	this->memo->GetLine(0)->SetColumn(0);
}

void OtherNoteForm::Save() {
	fstream fs("aha.txt", ios::out | ios::trunc);
	CharacterFaces *characterFaces = CharacterFaces::Instance(0);
	fs<<characterFaces->GetFontFamily()<<"\r\n"<<characterFaces->GetFontSize()<<"\r\n";
	Line *line;
	Long i = 0;
	while(i < this->memo->GetLength()) {
		line = this->memo->GetLine(i);
		MakeStringVisitor makeStringVisitor;
		line->Accept(&makeStringVisitor);
		fs<<makeStringVisitor.GetCompleteString().c_str()<<"\r\n";
		i++;
	}
	fs.close();
}
*/