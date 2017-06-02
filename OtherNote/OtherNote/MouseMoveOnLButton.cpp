// MouseMoveOnLButton.cpp

#include "MouseMoveOnLButton.h"

MouseMoveOnLButton::MouseMoveOnLButton(OtherNoteForm *otherNoteForm)
	:MouseMove(otherNoteForm) {
}

MouseMoveOnLButton::MouseMoveOnLButton(const MouseMoveOnLButton& source)
	:MouseMove(source) {
}

MouseMoveOnLButton::~MouseMoveOnLButton() {

}

MouseMoveOnLButton& MouseMoveOnLButton::operator=(const MouseMoveOnLButton& source) {
	MouseMove::operator=(source);
	return *this;
}

void MouseMoveOnLButton::Action(UINT nFlags, CPoint point) {

}