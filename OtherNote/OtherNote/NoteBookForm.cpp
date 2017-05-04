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
	ON_MESSAGE(WM_IME_STARTCOMPOSITION, OnImeStartComposition)
	ON_MESSAGE(WM_IME_COMPOSITION, OnImeComposition)
	//ON_MESSAGE(WM_IME_ENDCOMPOSITION, OnImeEndComposition)
	//ON_MESSAGE(WM_IME_CHAR, OnImeChar)
END_MESSAGE_MAP()

NoteBookForm::NoteBookForm() {
	this->endComposition = false;
}

BOOL NoteBookForm::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CFrameWnd::OnCreate(lpCreateStruct);
	this->memo = new Memo(10000);
	
	return FALSE;
}

void NoteBookForm::OnPaint() {
	CPaintDC dc(this);	
	CString characters;
	
	Long i = 0;
	Character *characterLink;
	while (i < this->memo->GetAt(0).GetLength()) {
		characterLink = this->memo->GetAt(0).GetAt(i);

		if (dynamic_cast<SingleCharacter*>(characterLink)) {
			characters += (dynamic_cast<SingleCharacter*>(characterLink))->GetValue();
		}
		else if (dynamic_cast<DoubleCharacter*>(characterLink)) {
			characters += (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue()[0];
			characters += (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue()[1];
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
	//Character *temp = 0;
	//if (this->memo->GetLength() != 0) {
	//	temp = this->memo->GetAt(this->memo->GetLength() - 1);
	//}
	//
	//if (dynamic_cast<DoubleCharacter*>(temp)) {
	//	this->memo->Erase(this->memo->GetLength() - 1);
	//}
	this->endComposition = false;

	if (nChar == 13) {
		this->memo->Erase();
	}
	else {
		this->memo->Write(nChar);
	}
	this->RedrawWindow();	
}

LRESULT NoteBookForm::OnImeComposition(WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(wParam);
	UNREFERENCED_PARAMETER(lParam);

	char composition[2];
	composition[0] = *(((char*)&wParam) + 1);
	composition[1] = *((char*)&wParam);

	Long row;
	Long column;
	Line *lineLink;
	Character *characterLink;

	if (lParam & GCS_COMPSTR) {
		row = this->memo->GetRow();
		column=this->memo->GetColumn();
		lineLink = &this->memo->GetAt(row);
		characterLink = lineLink->GetAt(column - 1);

		//if (dynamic_cast<DoubleCharacter*>(characterLink) && this->endComposition==false) {
		if (this->endComposition == false) {

			this->memo->Erase();
		}
		this->endComposition = false;
		this->memo->Write(composition);

	}
	if (lParam & GCS_RESULTSTR) {
		//if (this->endComposition == false) {
			this->endComposition = true;
		//}
		this->memo->Erase();
		this->memo->Write(composition);
		//this->memo->SetColumn(this->memo->GetColumn() + 1);
	}
	this->RedrawWindow();
	
	//
	//
	//Character *temp = 0;
	//if (this->memo->GetLength() != 0) {
	//	temp = this->memo->GetAt(this->memo->GetLength() - 1);
	//}	
	//	
	//if (lParam & GCS_COMPSTR) {
	//	if (dynamic_cast<DoubleCharacter*>(temp)) {
	//		//this->memo->Erase(this->memo->GetLength() - 1);
	//	}		
	//	composition[0] = *(((char*)&wParam) + 1);
	//	composition[1] = *((char*)&wParam);
	//	this->memo->Write(composition);
	//}
	//else if (lParam & GCS_RESULTSTR) {
	//	//this->memo->Erase(this->memo->GetLength() - 1);
	//	composition[0] = *(((char*)&wParam) + 1);
	//	composition[1] = *((char*)&wParam);
	//	this->memo->Write(composition);
	//	this->memo->Write(composition);
	//}
	//if (lParam & GCS_COMPSTR) {
	//	this->RedrawWindow();
	//}
	return 0;
}

LRESULT NoteBookForm::OnImeStartComposition(WPARAM wParam, LPARAM lParam) {
	this->memo->Write(' ');
	this->endComposition = false;
	return 0;
}

//LRESULT NoteBookForm::OnImeEndComposition(WPARAM wParam, LPARAM lParam) {
//	this->endComposition = false;
//	return 0;
//}


//LRESULT NoteBookForm::OnImeChar(WPARAM wParam, LPARAM lParam) {
//	char composition[2];
//
//	this->memo->Erase(this->memo->GetLength() - 1);
//	composition[0] = *(((char*)&wParam) + 1);
//	composition[1] = *((char*)&wParam);
//	this->memo->Write(composition);
//
//	this->memo->characters.length++;
//	this->memo->length++;
//
//	this->RedrawWindow();
//
//	return 0;
//}

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