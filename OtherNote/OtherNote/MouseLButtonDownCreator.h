// MouseLButtonDownCreator.h

#ifndef _MOUSELBUTTONDOWNCREATOR_H
#define _MOUSELBUTTONDOWNCREATOR_H

#include "OtherNoteForm.h"
#include "MouseLButtonDown.h"
#include <afxwin.h>

class MouseLButtonDownCreator {
public:
	MouseLButtonDownCreator(OtherNoteForm *otherNoteForm);
	MouseLButtonDownCreator(const MouseLButtonDownCreator& source);
	~MouseLButtonDownCreator();
	MouseLButtonDownCreator& operator=(const MouseLButtonDownCreator& source);
	MouseLButtonDown* Create(UINT nFlags, CPoint point);
private:
	OtherNoteForm *otherNoteForm;
};



#endif //_MOUSELBUTTONDOWNCREATOR_H