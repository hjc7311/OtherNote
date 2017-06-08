//OtherNoteForm.cpp

#include "OtherNoteForm.h"
#include "Memo.h"
#include "Line.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
#include "CharacterFaces.h"
#include "MakeStringVisitor.h"
#include "HorizontalScroll.h"
#include "VerticalScroll.h"
#include "Caret.h"
#include "HScrollActionCreator.h"
#include "VScrollActionCreator.h"
#include "ScrollAction.h"
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
	ON_WM_SIZE()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
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

void OtherNoteForm::OnSize(UINT nType, int cx, int cy) {
	this->horizontalScroll = new HorizontalScroll(this);
	this->verticalScroll = new VerticalScroll(this);
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
	SCROLLINFO scrinfo;
	SCROLLINFO vScrinfo;
	this->horizontalScroll->GetScrollBar()->GetScrollInfo(&scrinfo);
	this->verticalScroll->GetScrollBar()->GetScrollInfo(&vScrinfo);
	//
	//CScrollBar *csb=this->hScroll->GetScroll();
	//csb->GetScrollBarInfo();
	//
	CRect rect;
	this->GetClientRect(&rect);
	CharacterFaces *characterFaces = CharacterFaces::Instance(0);
	CRect rrect(-(scrinfo.nPos), -(vScrinfo.nPos), 10000, 10000);
	PaintVisitor paintVisitor(&dc, &rrect);	
	this->memo->Accept(&paintVisitor);
}

//void OtherNoteForm::OnPaint() {
//	CPaintDC dc(this);
//	//CRect rect = { 0,0,2000,2000 };
//	CRect rect;
//	GetClientRect(&rect);
//	PaintVisitor paintVisitor(&dc, &rect);
//
//	this->memo->Accept(&paintVisitor);
//}


void OtherNoteForm::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {
	if (nChar >= 32 && nChar <= 126) {
		Line *line = this->memo->GetLine(this->memo->GetRow());
		line->Write(nChar);
		this->horizontalScroll->UpdateLine();
		this->horizontalScroll->ScrollNextCharacter();
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
			caret->ChangeCaret();
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
void OtherNoteForm::Load() {
	fstream fs("aha.txt", ios::in);
	if (!fs.fail()) {
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
		while (!fs.eof()) {
			line = this->memo->GetLine(j);
			Long length = string(buffer).length();
			Long i = 0;
			while (i < length - 1) {
				if (buffer[i] >= 0 && buffer[i] <= 127) {
					line->Write(buffer[i]);
				}
				else {
					doubleCharacter[0] = buffer[i];
					doubleCharacter[1] = buffer[i + 1];
					i++;
					line->Write(doubleCharacter);
				}
				i++;
			}
			this->memo->AddLine();
			j++;
			fs.getline(buffer, sizeof(buffer));
		}
		this->memo->RemoveLine(this->memo->GetLength() - 1);
		fs.close();
	}
	this->memo->SetRow(0);
	this->memo->GetLine(0)->SetColumn(0);
}

void OtherNoteForm::Save() {
	fstream fs("aha.txt", ios::out | ios::trunc);
	CharacterFaces *characterFaces = CharacterFaces::Instance(0);
	fs << characterFaces->GetFontFamily() << "\r\n" << characterFaces->GetFontSize() << "\r\n";
	Line *line;
	Long i = 0;
	while (i < this->memo->GetLength()) {
		line = this->memo->GetLine(i);
		MakeStringVisitor makeStringVisitor;
		line->Accept(&makeStringVisitor);
		fs << makeStringVisitor.GetCompleteString().c_str() << "\r\n";
		i++;
	}
	fs.close();
}
*/


void OtherNoteForm::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) {
	HScrollActionCreator hScrollActionCreator;
	ScrollAction *scrollAction = hScrollActionCreator.Create(this->horizontalScroll, nSBCode, nPos, pScrollBar);

	if(scrollAction != 0) {
		scrollAction->Action(nSBCode, nPos, pScrollBar);
	}
}

void OtherNoteForm::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) {
	VScrollActionCreator vScrollActionCreator;
	ScrollAction *scrollAction = vScrollActionCreator.Create(this->verticalScroll, nSBCode, nPos, pScrollBar);
	
	if(scrollAction != 0) {
		scrollAction->Action(nSBCode, nPos, pScrollBar);
	}
}