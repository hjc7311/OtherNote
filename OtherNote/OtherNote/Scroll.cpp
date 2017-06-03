// Scroll.cpp

#include "Scroll.h"

Scroll::Scroll(OtherNoteForm *otherNoteForm) {
	this->otherNoteForm = otherNoteForm;
	this->scrollBar = new CScrollBar;
}

Scroll::Scroll(const Scroll& source) {
	this->otherNoteForm = source.otherNoteForm;
	this->scrollBar = source.scrollBar;
}

Scroll::~Scroll() {
	if(this->scrollBar != 0) {
		delete this->scrollBar;
	}
}

Scroll& Scroll::operator=(const Scroll& source) {
	if(this->scrollBar != 0) {
		delete this->scrollBar;
	}
	this->scrollBar = source.scrollBar;
	this->otherNoteForm = source.otherNoteForm;
	return *this;
}
