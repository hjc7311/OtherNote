// MouseLButtonUp.h

#ifndef _MOUSELBUTTONUP_H
#define _MOUSELBUTTONUP_H

#include "OtherNoteForm.h"

class MouseLButtonUp {
public:
	MouseLButtonUp(OtherNoteForm *otherNoteForm);
	MouseLButtonUp(const MouseLButtonUp& source);
	~MouseLButtonUp();
	MouseLButtonUp& operator=(const MouseLButtonUp& source);
	virtual void Action(UINT nFlags, CPoint point);
protected:
	OtherNoteForm *otherNoteForm;
};


#endif //_MOUSELBUTTONUP_H