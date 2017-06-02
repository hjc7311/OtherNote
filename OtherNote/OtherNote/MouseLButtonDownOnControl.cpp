// MouseLButtonDownOnControl.cpp

#include "MouseLButtonDownOnControl.h"
#include "MouseLButtonDown.h"

MouseLButtonDownOnControl::MouseLButtonDownOnControl(OtherNoteForm *otherNoteForm)
	:MouseLButtonDown(otherNoteForm) {
}

MouseLButtonDownOnControl::MouseLButtonDownOnControl(const MouseLButtonDownOnControl& source)
	:MouseLButtonDown(source.otherNoteForm) {
}

MouseLButtonDownOnControl::~MouseLButtonDownOnControl() {
}

MouseLButtonDownOnControl& MouseLButtonDownOnControl::operator=(const MouseLButtonDownOnControl& source) {
	MouseLButtonDown::operator=(source);
	return *this;
}

void MouseLButtonDownOnControl::Action(UINT nFlags, CPoint point) {
}