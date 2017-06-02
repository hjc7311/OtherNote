// MouseMoveCreator.h

#ifndef _MOUSEMOVECREATOR_H
#define _MOUSEMOVECREATOR_H

#include "MouseMove.h"
#include <afxwin.h>
using namespace std;

class MouseMoveCreator {
public:
	MouseMoveCreator(OtherNoteForm *otherNoteForm);
	MouseMoveCreator(const MouseMoveCreator& source);
	~MouseMoveCreator();
	MouseMoveCreator& operator=(const MouseMoveCreator& source);
	MouseMove* Create(UINT nFlags, CPoint point);
private:
	OtherNoteForm *otherNoteForm;
};

#endif //_MOUSEMOVECREATOR_H