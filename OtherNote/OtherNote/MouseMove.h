// MouseMove.h

#ifndef _MOUSEMOVE_H
#define _MOUSEMOVE_H

#include "OtherNoteForm.h"
#include <afxwin.h>
using namespace std;

class MouseMove {
public:
	MouseMove(OtherNoteForm *otherNoteForm = 0);
	MouseMove(const MouseMove& source);
	~MouseMove();
	MouseMove& operator=(const MouseMove& source);
	virtual void Action(UINT nFlags, CPoint point) {};
protected:
	OtherNoteForm *otherNoteForm;
};

#endif //_MOUSEMOVE_H