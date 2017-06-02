// MouseLButtonUpCreator.h

#ifndef _MOUSELBUTTONUPCREATOR_H
#define _MOUSELBUTTONUPCREATOR_H

#include "OtherNoteForm.h"
#include "MouseLButtonUp.h"
#include <afxwin.h>

class MouseLButtonUpCreator {
public: 
	MouseLButtonUpCreator(OtherNoteForm *otherNoteForm);
	MouseLButtonUpCreator(const MouseLButtonUpCreator& source);
	~MouseLButtonUpCreator();
	MouseLButtonUpCreator& operator=(const MouseLButtonUpCreator& source);
	MouseLButtonUp* Create(UINT nFlags, CPoint point);
private:
	OtherNoteForm *otherNoteForm;
};


#endif //_MOUSELBUTTONUPCREATOR_H