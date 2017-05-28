// NoteBookForm.cpp

#include "NoteBookForm.h"
#include "Memo.h"
#include "Line.h"
#include "CharacterFaces.h"
#include "Character.h"
#include "Caret.h"

BEGIN_MESSAGE_MAP(NoteBookForm, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_MESSAGE(WM_IME_COMPOSITION, OnImeComposition)
END_MESSAGE_MAP()

NoteBookForm::NoteBookForm() {

}


BOOL NoteBookForm::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CFrameWnd::OnCreate(lpCreateStruct);
	this->memo = new Memo;

	this->dc = new CPaintDC(this);
	CharacterFaces *characterFaces = CharacterFaces::Instance(this->dc);
	
	//this->point = new CPoint(0, 0);

	//this->CreateSolidCaret(10, 10);
	//SetCaretPos(10);
	//this->ShowCaret();
	
	Caret *caret = Caret::Instance(this);
	
	this->endComposition = true;
	
	return FALSE;
}

#include "PaintVisitor.h"
void NoteBookForm::OnPaint() {
	CPaintDC dc(this);

	PaintVisitor paintVisitor(&dc);

	//PaintVisitor paintVisitor(this->dc);

	this->memo->Accept(&paintVisitor);
}

void NoteBookForm::OnClose() {

	Caret *caret = Caret::Instance(this);
	if (caret != 0) {
		delete caret;
	}
	//delete this->point;
	if (this->dc != 0) {
		delete this->dc;

	}
	if (this->memo != 0) {
		delete this->memo;

	}
	CFrameWnd::OnClose();
}


void NoteBookForm::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {
	
	Line *lineLink = this->memo->GetLine(this->memo->GetRow());

	Caret *caret = Caret::Instance(this);

	if (nChar == VK_RETURN) {
		this->memo->AddLine();
		lineLink = this->memo->GetLine(this->memo->GetRow());

		caret->MoveNextLine();
	}
	else if (nChar == VK_TAB) {
		lineLink->Write('\t');
		
		//CharacterFaces *characterFaces = CharacterFaces::Instance(this->dc);
		//CSize size(this->dc->GetTextExtent(CString('\t')));

		//caret->Move(Caret::xPosition + size.cx, Caret::yPosition + size.cy);

		//Long column = lineLink->GetColumn();
		//while (column % 1 != 0) {
		//	caret->MoveNextCharacter();
		//	column++;
		//}
		caret->MoveNextTab();
		//caret->MoveNextCharacter();
	}
	//else if (nChar == VK_BACK) {
	else if (nChar==VK_BACK) {
		caret->MovePreviousCharacter();

		lineLink->Erase();
	}
	else {
		lineLink->Write(nChar);
		caret->MoveNextCharacter();

//		CharacterFaces *characterFaces = CharacterFaces::Instance(0);
		
//		CharacterSize characterSize = (*characterFaces)[nChar];
		
		//this->point->Offset(10, 0);
		
		//caret->SetCaretPosition(this, 10, 0);

	}
	
	this->RedrawWindow();	
}

LRESULT NoteBookForm::OnImeComposition(WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(wParam);
	UNREFERENCED_PARAMETER(lParam);

	char composition[2];
	composition[0] = *(((char*)&wParam) + 1);
	composition[1] = *((char*)&wParam);

	Line *lineLink = this->memo->GetLine(this->memo->GetRow());

	Caret *caret = Caret::Instance(this);
	caret->ChangeImeCaret();


	if (lParam & GCS_COMPSTR) {
		if (this->endComposition == false) {
			lineLink->Erase();
		}
		this->endComposition = false;
		lineLink->Write(composition);

	} 
	
	else if (lParam & GCS_RESULTSTR) {
		this->endComposition = true;
	
		lineLink->Erase();
		lineLink->Write(composition);

		caret->MoveNextCharacter();
		caret->ChangeCaret();
	}

	this->RedrawWindow();

	return 0;
}

void NoteBookForm::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
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
			Long currentXPosition = caret->GetXPosition();

			caret->MovePreviousLine();
			this->memo->MoveUpRow();

			line = this->memo->GetLine(this->memo->GetRow());
			Long totalWidth = 0;
			Long i = 0;
			while (i < line->GetLength()) {
				Character *character = line->GetCharacter(i);
				totalWidth += character->GetWidth();
				i++;
			}

			Long xPosition = 0;
			if (xPosition > totalWidth) {
				xPosition = totalWidth;
			}
			else {

			}
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
}