// MouseRButtonDown.h

#ifndef _MOUSERBUTTONDONW_H
#define _MOUSERBUTTONDONW_H

#include "OtherNoteForm.h"
#include <afxwin.h>

class MouseRButtonDown {
public:
	MouseRButtonDown(OtherNoteForm *otherNoteForm);
	MouseRButtonDown(const MouseRButtonDown& source);
	~MouseRButtonDown();
	MouseRButtonDown& operator=(const MouseRButtonDown& source);
	virtual void Action(UINT nFlags, CPoint point);
protected:
	OtherNoteForm *otherNoteForm;
};



#endif //_MOUSERBUTTONDONW_H