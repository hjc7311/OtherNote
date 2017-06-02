// MouseRButtonDownCreator.h

#ifndef _MOUSERBUTTONDOWNCREATOR_H
#define _MOUSERBUTTONDOWNCREATOR_H

#include "OtherNoteForm.h"
#include "MouseRButtonDown.h"
#include <afxwin.h>

class MouseRButtonDownCreator {
	MouseRButtonDownCreator(OtherNoteForm *otherNoteForm);
	MouseRButtonDownCreator(const MouseRButtonDownCreator& source);
	~MouseRButtonDownCreator();
	MouseRButtonDownCreator& operator=(const MouseRButtonDownCreator& source);
	MouseRButtonDown* Create(UINT nFlags, CPoint point);
private:
	OtherNoteForm *otherNoteForm;
};


#endif //_MOUSERBUTTONDOWNCREATOR_H