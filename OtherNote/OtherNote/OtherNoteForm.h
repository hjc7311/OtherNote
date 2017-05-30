//OtherNoteForm.h

#ifndef _OTHERNOTEFORM_H
#define _OTHERNOTEFORM_H

#include <afxwin.h>
using namespace std;

class Memo;
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

	DECLARE_MESSAGE_MAP()
private:
	Memo *memo;
	bool endComposition;
};

inline Memo* OtherNoteForm::GetMemo() const {
	return const_cast<Memo*>(this->memo);
}

#endif	//_OTHERNOTEFORM_H