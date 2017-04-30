// NoteBookForm.cpp

#include "NoteBookForm.h"
#include "Memo.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
#include <string>
#include <Windows.h>

BEGIN_MESSAGE_MAP(NoteBookForm, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

NoteBookForm::NoteBookForm() {}

BOOL NoteBookForm::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CFrameWnd::OnCreate(lpCreateStruct);
	this->memo = new Memo(10);
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
	
//	dc.TextOut(0, 0, singleCharacters, strlen(singleCharacters));
	dc.TextOut(0, 0, characters);

	//CRect client;
	//GetClientRect(&client);
	
}

void NoteBookForm::OnClose() {
	delete this->memo;
	CFrameWnd::OnClose();
}

void NoteBookForm::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {

	/*HWND hWnd = this->m_hWnd;
	HIMC hImc;
	int len;
	string *inputText;
	char input[10];

	hImc = ImmGetContext(hWnd);
	len = ImmGetCompositionString(hImc, GCS_COMPSTR, NULL, 0);
	ImmGetCompositionString(hImc, GCS_COMPSTR, input, len);
	input[len] = '\0';
	inputText = new string(input);

	this->memo->Write(*inputText);*/

	string out;
	//char output;
	SendMessage(WM_IME_COMPOSITION, (WPARAM)&out, 0);
	string *outputString = new string(out);
	this->memo->Write(*outputString);


	//if (nChar == 13) {
	//	
	//	this->memo->Write("°¡");
	//}
	//if (nChar >= 65 && nChar <= 90) {
	//	this->memo->Write(nChar);
	//}
	//if (nChar == 229) {
	//	this->memo->Write(65);
	//}

	this->RedrawWindow();
	
	//this->UpdateWindow();
	
	//CPaintDC dc(this);
	//CString name;
	//name = "abc";
	//char character[5];
	//character[0] = nChar;
	//character[1] = '\0';

	//dc.TextOut(0, 0, name);
}

