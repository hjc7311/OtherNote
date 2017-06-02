// MouseLButtonDown.cpp

#include "MouseLButtonDown.h"

MouseLButtonDown::MouseLButtonDown(OtherNoteForm *otherNoteForm) {
	this->otherNoteForm = otherNoteForm;
}

MouseLButtonDown::MouseLButtonDown(const MouseLButtonDown& source) {
	this->otherNoteForm = source.otherNoteForm;
}

MouseLButtonDown::~MouseLButtonDown() {
}

MouseLButtonDown& MouseLButtonDown::operator=(const MouseLButtonDown& source) {
	this->otherNoteForm = source.otherNoteForm;
	return *this;
}