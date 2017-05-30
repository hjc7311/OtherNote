//KeyAction.cpp

#include "KeyAction.h"
#include "OtherNoteForm.h"

KeyAction::KeyAction(OtherNoteForm *otherNoteForm)
{
	this->otherNoteForm = otherNoteForm;
}

KeyAction::KeyAction(const KeyAction& source) {
	this->otherNoteForm = source.otherNoteForm;
}

KeyAction::~KeyAction() {

}

KeyAction& KeyAction::operator=(const KeyAction& source) {
	this->otherNoteForm = source.otherNoteForm;

	return *this;
}