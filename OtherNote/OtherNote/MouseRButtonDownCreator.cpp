// MouseRButtonDownCreator.cpp

#include "MouseRButtonDownCreator.h"

MouseRButtonDownCreator::MouseRButtonDownCreator(OtherNoteForm *otherNoteForm) {
	this->otherNoteForm = otherNoteForm;
}

MouseRButtonDownCreator::MouseRButtonDownCreator(const MouseRButtonDownCreator& source) {
	this->otherNoteForm = source.otherNoteForm;
}

MouseRButtonDownCreator::~MouseRButtonDownCreator() {
}

MouseRButtonDownCreator& MouseRButtonDownCreator::operator=(const MouseRButtonDownCreator& source) {
	this->otherNoteForm = source.otherNoteForm;
	return *this;
}

MouseRButtonDown* MouseRButtonDownCreator::Create(UINT nFlags, CPoint point) {
	
	MouseRButtonDown *mouseRButtonDown = new MouseRButtonDown(this->otherNoteForm);

	return mouseRButtonDown;
}