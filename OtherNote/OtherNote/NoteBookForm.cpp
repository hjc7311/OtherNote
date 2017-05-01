// NoteBookForm.cpp

#include "NoteBookForm.h"
#include "Memo.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
#include <afxmsg_.h>
#include <Windows.h>

BEGIN_MESSAGE_MAP(NoteBookForm, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_CHAR()
	ON_MESSAGE(WM_IME_COMPOSITION, OnTest2)
END_MESSAGE_MAP()

NoteBookForm::NoteBookForm() {}

BOOL NoteBookForm::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CFrameWnd::OnCreate(lpCreateStruct);
	this->memo = new Memo(100);
	//this->memo->Write("¤§");
	//this->memo->Write("¤¿");
	//this->memo->Write("´Ù");
	//this->memo->Write('a');

	return FALSE;
}

void NoteBookForm::OnPaint() {
	CPaintDC dc(this);
	
	CString characters;
	
	Long i = 0;
	Character *characterLink;
	while (i < this->memo->GetLength()) {
		characterLink = this->memo->GetAt(i);

		if (dynamic_cast<SingleCharacter*>(characterLink)) {
			characters += (dynamic_cast<SingleCharacter*>(characterLink))->GetValue();
		}
		else if (dynamic_cast<DoubleCharacter*>(characterLink)) {
			characters += (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue().c_str();
		}
		i++;
	}
	
	dc.TextOut(0, 0, characters);
}

void NoteBookForm::OnClose() {
	delete this->memo;
	CFrameWnd::OnClose();
}

void NoteBookForm::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {
	this->memo->Write(nChar);
	this->RedrawWindow();
}

LRESULT NoteBookForm::OnTest2(WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(wParam);
	UNREFERENCED_PARAMETER(lParam);

	this->WindowProc(WM_IME_CHAR, wParam, 0);
	
	return 0;
}

//
//void NoteBookForm::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
//
//	if (nChar == 13) {
//		
//		this->memo->Write("°¡");
//	}
//	if (nChar >= 65 && nChar <= 90) {
//		this->memo->Write(nChar);
//	}
//	if (nChar == 230) {
//		this->memo->Write(65);
//	}
//
//	this->RedrawWindow();
//	
//	//this->UpdateWindow();
//	
//	//CPaintDC dc(this);
//	//CString name;
//	//name = "abc";
//	//char character[5];
//	//character[0] = nChar;
//	//character[1] = '\0';
//
//	//dc.TextOut(0, 0, name);
//}

