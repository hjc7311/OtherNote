// MouseMoveCreator.cpp

#include "MouseMoveCreator.h"
#include "MouseMoveOnLButton.h"

MouseMoveCreator::MouseMoveCreator(OtherNoteForm *otherNoteForm) {
	this->otherNoteForm = otherNoteForm;
}

MouseMoveCreator::MouseMoveCreator(const MouseMoveCreator& source) {
	this->otherNoteForm = source.otherNoteForm;
}

MouseMoveCreator::~MouseMoveCreator() {

}

MouseMoveCreator& MouseMoveCreator::operator=(const MouseMoveCreator& source) {
	this->otherNoteForm = source.otherNoteForm;
	return *this;
}

MouseMove* MouseMoveCreator::Create(UINT nFlags, CPoint point) {
	
	MouseMove *mouseMove;
	
	if(nFlags == MK_LBUTTON) {
		mouseMove = new MouseMoveOnLButton(this->otherNoteForm);
	}

	return mouseMove;
}