#pragma once
//Mouse.h

#ifndef _MOUSE_H
#define _MOUSE_H

#include <afxwin.h>
using namespace std;

typedef signed long int Long;

class OtherNoteForm;
class Mouse :public CFrameWnd {
public:
	Mouse(OtherNoteForm *otherNoteForm = 0);
	Mouse(const Mouse& source);
	~Mouse();
	Mouse& operator=(const Mouse& source);
	
	virtual void OnMouseMove(UINT nFlags, CPoint point);
	virtual void OnLButtonDown(UINT nFlags, CPoint point);
//	virtual void OnLButtonUP(UINT nFlags, CPoint point);
	//virtual void OnLButtonDblClk(UINT nFlags, CPoint point);
	//virtual void OnRButtonDown(UINT nFlags, CPoint point);
	//virtual void OnRButtonUP(UINT nFlags, CPoint point);
	//virtual void OnRButtonDblClk(UINT nFlags, CPoint point);
private:
	static Mouse *instance;
	OtherNoteForm *otherNoteForm;
//	Long pointerShape;
	
};

#endif	//_MOUSE_H