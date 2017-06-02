// MouseLButtonDown.h

#ifndef _MOUSELBUTTONDOWN_H
#define _MOUSELBUTTONDOWN_H

#include <afxwin.h>
#include "OtherNoteForm.h"

class MouseLButtonDown {
public:
	MouseLButtonDown(OtherNoteForm *otherNoteForm);
	MouseLButtonDown(const MouseLButtonDown& source);
	~MouseLButtonDown();
	MouseLButtonDown& operator=(const MouseLButtonDown& source);
	virtual void Action(UINT nFlags, CPoint point) {};
protected:
	OtherNoteForm *otherNoteForm;
};


#endif //_MOUSELBUTTONDOWN_H