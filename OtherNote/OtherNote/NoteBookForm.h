// NoteBookForm.h

#ifndef _NOTEBOOKFORM_H
#define _NOTEBOOKFORM_H

#include <afxwin.h>

class Memo;
class Visitor;
class NoteBookForm:public CFrameWnd {	

public:
	NoteBookForm();
public:
	Memo *memo;
	Visitor *visitor;

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnClose();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg LRESULT OnImeComposition(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()
private:
	bool endComposition;
};

#endif	//_NOTEBOOKFORM_H