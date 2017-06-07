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
	//CRect arect;
	//this->GetClientRect(&arect);
	//CRect rrect(arect.left, arect.bottom-20, arect.right, arect.bottom);
	//scroll->Create(SBS_HORZ, rrect, this, 1);
	////scroll->SetScrollRange(0, 100);
	////scroll->SetScrollPos(0);
	//SCROLLINFO  scrinfo; 
	//scrinfo.cbSize = sizeof(scrinfo); 
	//scrinfo.fMask = SIF_ALL; 
	//scrinfo.nMin = 0;          // 최소값
	//scrinfo.nMax = 100;      // 최대값 
	//scrinfo.nPage = 50;      // 페이지단위 증가값 
	//scrinfo.nTrackPos = 50;  // 트랙바가 움직일때의 위치값 
	//scrinfo.nPos = 0;        // 위치 
	//scroll->SetScrollInfo(&scrinfo); 
	//scroll->ShowScrollBar(SB_BOTH);
	/*this->dc = new CDC;
	this->dc->CreateDCA("test", NULL, NULL, NULL);
	this->dc->CreateCompatibleDC(this->dc);*/
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
	/*Long width = characterFaces->GetCharacterSize(97).GetWidth();
	if (scrinfo.nMax - scrinfo.nPos - scrinfo.nPage < width) {
		width = scrinfo.nMax - scrinfo.nPos - scrinfo.nPage;
		scrinfo.nPos += width;
	}
	this->horizontalScroll->GetScrollBar()->SetScrollInfo(&scrinfo);*/
	//CRect rrect(-100*(scrinfo.nPos), 0 ,5000, rect.bottom-20);
	//this->GetClientRect(&rect);
	//CRect rrect(-((scrinfo.nPos)*width), rect.top, 5000, rect.bottom - 20);
	CRect rrect(-(scrinfo.nPos), -(vScrinfo.nPos), 10000, 10000);
	PaintVisitor paintVisitor(&dc, &rrect);	
	
	this->verticalScroll->UpdateLine();
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

		//Memo *memo = this->otherNoteForm->GetMemo();
		//Line *line = memo->GetLine(memo->GetRow());
		
		//라인끝에서 한글자 추가를 할 경우 움직인 클자의 width만큼 이동할 수 있도록 함
		/*Character *character = line->GetCharacter(line->GetColumn() - 1);
		Long moveWidth = character->GetWidth();
		this->horizontalScroll->ScrollNext(moveWidth);*/
		
		//if (line->GetLength() == line->GetColumn()) {
		this->horizontalScroll->UpdateLine();
		
		Long lineWidth = 0;
		Long i = 0;
		CRect rect;
		this->GetClientRect(&rect);
		while (i < line->GetLength()) {
			lineWidth += line->GetCharacter(i)->GetWidth();
			i++;
		}
		Long currentLineWidth = 0;
		i = 0;
		while (i < line->GetColumn()) {
			currentLineWidth += line->GetCharacter(i)->GetWidth();
			i++;
		}
		SCROLLINFO scrinfo;
		this->horizontalScroll->GetScrollBar()->GetScrollInfo(&scrinfo);

		if (currentLineWidth >= this->horizontalScroll->GetMaxLineSize()) {
			Long width = line->GetCharacter(line->GetColumn() - 1)->GetWidth();
			//if (scrinfo.nPos + scrinfo.nPage > currentLineWidth) {
				this->horizontalScroll->ScrollNext(width);
			//}
		}
		else if (currentLineWidth > scrinfo.nPos + scrinfo.nPage){
			CRect rect;
			this->GetClientRect(&rect);
			Long width = rect.right / 3;
			if ((this->horizontalScroll->GetMaxLineSize() - currentLineWidth) < width) {
				width = this->horizontalScroll->GetMaxLineSize() - currentLineWidth;
			}

			/*lineWidth = 0;
			while (i < line->GetColumn()) {
				lineWidth += line->GetCharacter(i)->GetWidth();
				i++;
			}*/
			/*SCROLLINFO scrinfo;
			this->horizontalScroll->GetScrollBar()->GetScrollInfo(&scrinfo);*/

			//if (scrinfo.nPos + scrinfo.nPage > lineWidth) {
			this->horizontalScroll->ScrollNext(width);
			//}			
		}
		//this->horizontalScroll->UpdateLine();
		//}
		/*else {
			Long i = 0;
			Long size = 0;
			while (i < line->GetColumn() - 1) {
				size += line->GetCharacter(i)->GetWidth();
				i++;
			}
			SCROLLINFO scrinfo;
			this->horizontalScroll->GetScrollBar()->GetScrollInfo(&scrinfo);
			if (scrinfo.nPos + scrinfo.nPage > size) {
				CRect rect;
				this->GetClientRect(&rect);
				Long width = rect.right / 3;
				this->horizontalScroll->ScrollNext(width);
			}
		}*/
		//this->horizontalScroll->UpdateLine();
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
	if(nSBCode == SB_LINERIGHT) {
		this->horizontalScroll->ScrollNextLine();
		/*SCROLLINFO  scrinfo;
		pScrollBar->GetScrollInfo(&scrinfo);
		scrinfo.nPos += 1;
		pScrollBar->SetScrollInfo(&scrinfo);
		CRect rect;
		this->GetClientRect(&rect);
		CRect rrect(rect.left, rect.top, rect.right, rect.bottom-20);
		this->ScrollWindow(-100,0, CRect(0, 0, 5000, rrect.bottom), CRect(200, 0, 400, 400));
		this->UpdateWindow();*/
		//CPaintDC dc(this);
		//CRect rrrect(rect.left-100, rect.top, 3000, rect.bottom-20);
		//PaintVisitor paintVisitor(&dc, &rrrect);
		//this->memo->Accept(&paintVisitor);
		//CRect rect(0, 0, 500, 500);
		//this->ScrollWindow(50,0,&rect,&rect);
	}

	if(nSBCode == SB_LINELEFT) {
		/*SCROLLINFO  scrinfo;
		pScrollBar->GetScrollInfo(&scrinfo);
		scrinfo.nPos -= 1;
		pScrollBar->SetScrollInfo(&scrinfo);*/
		this->horizontalScroll->ScrollPreviousLine();
	}

	if (nSBCode == SB_PAGERIGHT) {
		this->horizontalScroll->ScrollNextPage();
	}

	if (nSBCode == SB_PAGELEFT) {
		this->horizontalScroll->ScrollPreviousPage();
	}

	if (nSBCode == SB_THUMBTRACK) {
		/*SCROLLINFO  scrinfo;
		pScrollBar->GetScrollInfo(&scrinfo);
		scrinfo.nPos += scrinfo.nTrackPos;
		pScrollBar->SetScrollInfo(&scrinfo);*/
		this->horizontalScroll->MoveThumb();
	}

	if (nSBCode == SB_THUMBPOSITION) {
		this->horizontalScroll->MoveThumb();
	}
	
	//this->UpdateWindow();
}

void OtherNoteForm::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) {
	if (nSBCode == SB_LINEDOWN) {
		this->verticalScroll->ScrollNextLine();
	}

	if (nSBCode == SB_LINEUP) {
		this->verticalScroll->ScrollPreviousLine();
	}

	if (nSBCode == SB_PAGEDOWN) {
		this->verticalScroll->ScrollNextPage();
	}

	if (nSBCode == SB_PAGEUP) {
		this->verticalScroll->ScrollPreviousPage();
	}

	if (nSBCode == SB_THUMBPOSITION) {
		this->verticalScroll->MoveThumb();
	}

	if (nSBCode == SB_THUMBTRACK) {
		this->verticalScroll->MoveThumb();
	}

	//this->UpdateWindow();
}