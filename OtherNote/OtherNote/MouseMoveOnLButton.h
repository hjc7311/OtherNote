// MouseMoveOnLButton.h

#ifndef _MOUSEMOVEONLBUTTON_H
#define _MOUSEMOVEONLBUTTON_H

#include "MouseMove.h"
#include <afxwin.h>

class MouseMoveOnLButton : public MouseMove {
public:
	MouseMoveOnLButton(OtherNoteForm *otherNoteForm);
	MouseMoveOnLButton(const MouseMoveOnLButton& source);
	~MouseMoveOnLButton();
	MouseMoveOnLButton& operator=(const MouseMoveOnLButton& source);
	virtual void Action(UINT nFlags, CPoint point);
};



#endif //_MOUSEMOVEONLBUTTON_H