// NoteBookForm.h

#ifndef _NOTEBOOKFORM_H
#define _NOTEBOOKFORM_H

#include <afxwin.h>

class Memo;
class NoteBookForm:public CFrameWnd {	

public:
	NoteBookForm();
public:
	Memo *memo;

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnClose();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg LRESULT OnTest2(WPARAM wParam, LPARAM lParam);
	
	DECLARE_MESSAGE_MAP()

};

#endif	//_NOTEBOOKFORM_H