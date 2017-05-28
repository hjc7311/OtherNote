// NoteBookForm.h

#ifndef _NOTEBOOKFORM_H
#define _NOTEBOOKFORM_H

#include <afxwin.h>

class Memo;
class Visitor;
class NoteBookForm:public CFrameWnd {	

public:
	NoteBookForm();
	void Load();
	void Save();
	Memo* GetMemo() const;
	CPaintDC* GetDC() const;
public:
	Visitor *visitor;

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnClose();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg LRESULT OnImeComposition(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()
private:
	bool endComposition;
	CPaintDC *dc;
public:
	Memo *memo;
};

inline Memo* NoteBookForm::GetMemo() const {
	return const_cast<Memo*>(this->memo);
}

inline CPaintDC* NoteBookForm::GetDC() const {
	return const_cast<CPaintDC*>(this->dc);
}

#endif	//_NOTEBOOKFORM_H