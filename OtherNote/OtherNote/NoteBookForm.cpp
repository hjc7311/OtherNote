// NoteBookForm.cpp

#include "NoteBookForm.h"
#include "Memo.h"
#include "Line.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
#include <Windows.h>

BEGIN_MESSAGE_MAP(NoteBookForm, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_CHAR()
	ON_MESSAGE(WM_IME_COMPOSITION, OnImeComposition)
END_MESSAGE_MAP()

NoteBookForm::NoteBookForm() {
}

BOOL NoteBookForm::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CFrameWnd::OnCreate(lpCreateStruct);
	this->memo = new Memo;
	this->memo->AddLine(new Line);
	this->endComposition = true;

	return FALSE;
}
#include "PaintVisitor.h"
void NoteBookForm::OnPaint() {
	CPaintDC dc(this);
/*
	RECT rect;
	GetClientRect(&rect);

	CFont font;
	font.CreatePointFont(200, "Tahoma");
	dc.SelectObject(&font);
*/
	PaintVisitor paintVisitor(&dc);

	CString characters;
	Long i = 0;
	Long j;
	Line *lineLink;
	Character *characterLink;
	
	this->memo->Accept(&paintVisitor);
	
	/*Long i = 0;
	Long j;
	Line *lineLink;
	Character *characterLink;
	while (i < this->memo->GetLength()) {
		lineLink = this->memo->GetLine(i);
		j = 0;
		while (j < lineLink->GetLength()){
			characterLink = lineLink->GetCharacter(j);
			if (dynamic_cast<SingleCharacter*>(characterLink)) {
				characters += (dynamic_cast<SingleCharacter*>(characterLink))->GetValue();
			}
			else if (dynamic_cast<DoubleCharacter*>(characterLink)) {
				characters += (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue()[0];
				characters += (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue()[1];
			}
			j++;
		}
		characters += '\n';
		i++;
	}
	dc.DrawText(characters, &rect, DT_EDITCONTROL|DT_WORDBREAK|DT_LEFT|DT_EXPANDTABS);*/
	//this->RedrawWindow();
}

void NoteBookForm::OnClose() {
	delete this->memo;
	CFrameWnd::OnClose();
}

void NoteBookForm::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {
	
	Line *lineLink = this->memo->GetLine(this->memo->row);

	if (nChar == VK_RETURN) {
		this->memo->AddLine(new Line);
		lineLink = this->memo->GetLine(this->memo->row);
	}
	else if (nChar == VK_TAB) {
		lineLink->Write('\t');
	}
	else {
		lineLink->Write(nChar);
	}
	this->RedrawWindow();	
}

LRESULT NoteBookForm::OnImeComposition(WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(wParam);
	UNREFERENCED_PARAMETER(lParam);

	char composition[2];
	composition[0] = *(((char*)&wParam) + 1);
	composition[1] = *((char*)&wParam);

	Line *lineLink = this->memo->GetLine(this->memo->row);

	if (lParam & GCS_COMPSTR) {

		if (this->endComposition == false) {
			lineLink->Erase();
		}
		this->endComposition = false;
		lineLink->Write(composition);
	}
	if (lParam & GCS_RESULTSTR) {
		this->endComposition = true;
	
		lineLink->Erase();
		lineLink->Write(composition);
	}
	this->RedrawWindow();

	return 0;
}