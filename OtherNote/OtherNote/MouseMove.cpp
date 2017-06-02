// MouseMove.cpp

#include "MouseMove.h"

MouseMove::MouseMove(OtherNoteForm *otherNoteForm) {
	this->otherNoteForm = otherNoteForm;
}

MouseMove::MouseMove(const MouseMove& source) {
	this->otherNoteForm = source.otherNoteForm;
}

MouseMove::~MouseMove() {
}

MouseMove& MouseMove::operator=(const MouseMove& source) {
	this->otherNoteForm = source.otherNoteForm;

	return *this;
}