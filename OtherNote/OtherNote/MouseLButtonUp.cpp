// MouseLButtonUp.cpp

#include "MouseLButtonUp.h"

MouseLButtonUp::MouseLButtonUp(OtherNoteForm *otherNoteForm) {
	this->otherNoteForm = otherNoteForm;
}

MouseLButtonUp::MouseLButtonUp(const MouseLButtonUp& source) {
	this->otherNoteForm = source.otherNoteForm;
}
MouseLButtonUp::~MouseLButtonUp() {
}

MouseLButtonUp& MouseLButtonUp::operator=(const MouseLButtonUp& source) {
	this->otherNoteForm = source.otherNoteForm;
	return *this;
}

void MouseLButtonUp::Action(UINT nFlags, CPoint point) {
}