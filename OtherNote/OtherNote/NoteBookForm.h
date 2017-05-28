// NoteBookForm.h

#ifndef _NOTEBOOKFORM_H
#define _NOTEBOOKFORM_H

//#include "Caret.h"
#include <afxwin.h>
using namespace std;

class Memo;
class Visitor;
class NoteBookForm:public CFrameWnd {	

public:
	NoteBookForm();

	Memo* GetMemo() const;
	CPaintDC* GetDC() const;
	//Caret& GetCaret() const;
//public:
//	Visitor *visitor;
//	CPaintDC *dc;
//	CPoint *point;
//
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnClose();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg LRESULT OnImeComposition(WPARAM wParam, LPARAM lParam);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	DECLARE_MESSAGE_MAP()
private:
	Memo *memo;
	CPaintDC *dc;
	//Caret caret;

	bool endComposition;
};

inline Memo* NoteBookForm::GetMemo() const {
	return const_cast<Memo*>(this->memo);
}

inline CPaintDC* NoteBookForm::GetDC() const {
	return const_cast<CPaintDC*>(this->dc);
}

//inline Caret& NoteBookForm::GetCaret() const {
//	return const_cast<Caret&>(this->caret);
//}

#endif	//_NOTEBOOKFORM_H