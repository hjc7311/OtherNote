//OtherNoteForm.h

#ifndef _OTHERNOTEFORM_H
#define _OTHERNOTEFORM_H

#include <afxwin.h>
using namespace std;

class Memo;
class HorizontalScroll;
class VerticalScroll;
class OtherNoteForm :public CFrameWnd {
public:
	OtherNoteForm();
	void Load();
	void Save();
	Memo* GetMemo() const;
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	afx_msg void OnPaint();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg LRESULT OnImeComposition(WPARAM wParam, LPARAM lParam);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSize(UINT nType, int cx, int cy);

	DECLARE_MESSAGE_MAP()
private:
	Memo *memo;
	bool endComposition;
	HorizontalScroll *hScroll;
	VerticalScroll *vScroll;
};

inline Memo* OtherNoteForm::GetMemo() const {
	return const_cast<Memo*>(this->memo);
}

#endif	//_OTHERNOTEFORM_H