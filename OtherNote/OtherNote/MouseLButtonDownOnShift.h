// MouseLButtonDownOnShift.h

#ifndef _MOUSELBUTTONDOWNONSHIFT_H
#define _MOUSELBUTTONDOWNONSHIFT_H

#include "MouseLButtonDown.h"

class MouseLButtonDownOnShift :public MouseLButtonDown {
public:
	MouseLButtonDownOnShift(OtherNoteForm *otherNoteForm);
	MouseLButtonDownOnShift(const MouseLButtonDownOnShift& source);
	~MouseLButtonDownOnShift();
	MouseLButtonDownOnShift& operator=(const MouseLButtonDownOnShift& source);
	virtual void Action(UINT nFlags, CPoint point);
};


#endif //_MOUSELBUTTONDOWNONSHIFT_H