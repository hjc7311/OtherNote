// MouseRButtonDown.cpp

#include "MouseRButtonDown.h"

MouseRButtonDown::MouseRButtonDown(OtherNoteForm *otherNoteForm) {
	this->otherNoteForm = otherNoteForm;
}

MouseRButtonDown::MouseRButtonDown(const MouseRButtonDown& source) {
	this->otherNoteForm = source.otherNoteForm;
}

MouseRButtonDown::~MouseRButtonDown() {
}

MouseRButtonDown& MouseRButtonDown::operator=(const MouseRButtonDown& source) {
	this->otherNoteForm = source.otherNoteForm;
	return *this;
}

void MouseRButtonDown::Action(UINT nFlags, CPoint point) {
}