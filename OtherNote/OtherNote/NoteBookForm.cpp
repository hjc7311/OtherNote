// NoteBookForm.cpp

#include "NoteBookForm.h"
#include "Memo.h"

BEGIN_MESSAGE_MAP(NoteBookForm, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_CLOSE()
END_MESSAGE_MAP()

NoteBookForm::NoteBookForm() {}

BOOL NoteBookForm::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CFrameWnd::OnCreate(lpCreateStruct);
	this->memo = new Memo(10);
	this->memo->Write('a');
	this->memo->Write('b');
	this->memo->Write('c');
	this->memo->Write('d');
	this->memo->Write('e');
	return FALSE;
}

void NoteBookForm::OnPaint() {
	
	CPaintDC dc(this);
	
	CString singleCharacters;
/*
	TCHAR singleCharacters[256];

	Long i = 0;
	while (i < this->memo->GetLength()) {
		singleCharacters[i] = this->memo->GetAt(i).GetValue();
		i++;
	}
	singleCharacters[i] = '\0';


	*/
	
	Long i = 0;
	while (i < this->memo->GetLength()) {
//		singleCharacters = singleCharacters + this->memo->GetAt(i).GetValue();
		singleCharacters += this->memo->GetAt(i).GetValue();

		i++;
	}
	
//	dc.TextOut(0, 0, singleCharacters, strlen(singleCharacters));
	dc.TextOut(0, 0, singleCharacters);

	//CRect client;
	//GetClientRect(&client);
	
}

void NoteBookForm::OnClose() {
	delete this->memo;
	CFrameWnd::OnClose();
}
