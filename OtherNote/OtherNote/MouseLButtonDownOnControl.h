// MouseLButtonDownOnControl.h

#ifndef _MOUSELBUTTONDOWNONCONTROL_H
#define _MOUSELBUTTONDOWNONCONTROL_H

#include "OtherNoteForm.h"
#include "MouseLButtonDown.h"

class MouseLButtonDownOnControl : public MouseLButtonDown {
public:
	MouseLButtonDownOnControl(OtherNoteForm *otherNoteForm);
	MouseLButtonDownOnControl(const MouseLButtonDownOnControl& source);
	~MouseLButtonDownOnControl();
	MouseLButtonDownOnControl& operator=(const MouseLButtonDownOnControl& source);
	virtual void Action(UINT nFlags, CPoint point);
};


#endif //_MOUSELBUTTONDOWNCONTROL_H