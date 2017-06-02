// MouseLButtonUpCreator.cpp

#include "MouseLButtonUpCreator.h"

MouseLButtonUpCreator::MouseLButtonUpCreator(OtherNoteForm *otherNoteForm) {
	this->otherNoteForm = otherNoteForm;
}

MouseLButtonUpCreator::MouseLButtonUpCreator(const MouseLButtonUpCreator& source) {
	this->otherNoteForm = source.otherNoteForm;
}

MouseLButtonUpCreator::~MouseLButtonUpCreator() {
}

MouseLButtonUpCreator& MouseLButtonUpCreator::operator=(const MouseLButtonUpCreator& source) {
	this->otherNoteForm = source.otherNoteForm;
	return *this;
}

MouseLButtonUp* MouseLButtonUpCreator::Create(UINT nFlags, CPoint point) {
	
	MouseLButtonUp* mouseLButtonUp = new MouseLButtonUp(this->otherNoteForm);

	return mouseLButtonUp;
}