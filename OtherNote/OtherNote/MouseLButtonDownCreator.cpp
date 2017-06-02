// MouseLButtonDownCreator.cpp

#include "MouseLButtonDownCreator.h"
#include "MouseLButtonDownOnControl.h"
#include "MouseLButtonDownOnShift.h"

MouseLButtonDownCreator::MouseLButtonDownCreator(OtherNoteForm *otherNoteForm) {
	this->otherNoteForm = otherNoteForm;
}

MouseLButtonDownCreator::MouseLButtonDownCreator(const MouseLButtonDownCreator& source) {
	this->otherNoteForm = source.otherNoteForm;
}

MouseLButtonDownCreator::~MouseLButtonDownCreator() {
}

MouseLButtonDownCreator& MouseLButtonDownCreator::operator=(const MouseLButtonDownCreator& source) {
	this->otherNoteForm = source.otherNoteForm;
	return *this;
}

MouseLButtonDown* MouseLButtonDownCreator::Create(UINT nFlags, CPoint point) {
	
	MouseLButtonDown* mouseLButtonDown;
	
	if(nFlags == MK_LBUTTON) {
		mouseLButtonDown = new MouseLButtonDown(this->otherNoteForm);
	}
	if(nFlags == MK_CONTROL) {
		mouseLButtonDown = new MouseLButtonDownOnControl(this->otherNoteForm);
	}
	if(nFlags == MK_SHIFT) {
		mouseLButtonDown = new MouseLButtonDownOnShift(this->otherNoteForm);
	}

	return mouseLButtonDown;
}