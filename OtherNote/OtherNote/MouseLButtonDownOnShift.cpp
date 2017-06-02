// MouseLButtonDownOnShift.cpp

#include "MouseLButtonDownOnShift.h"
#include "OtherNoteForm.h"

MouseLButtonDownOnShift::MouseLButtonDownOnShift(OtherNoteForm *otherNoteForm)
	:MouseLButtonDown(otherNoteForm) {
}

MouseLButtonDownOnShift::MouseLButtonDownOnShift(const MouseLButtonDownOnShift& source)
	:MouseLButtonDown(source.otherNoteForm) {
}

MouseLButtonDownOnShift::~MouseLButtonDownOnShift() {
}

MouseLButtonDownOnShift& MouseLButtonDownOnShift::operator=(const MouseLButtonDownOnShift& source) {
	MouseLButtonDown::operator=(source);
	return *this;
}

void MouseLButtonDownOnShift::Action(UINT nFlags, CPoint point) {
}