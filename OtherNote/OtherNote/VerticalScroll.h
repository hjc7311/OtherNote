#pragma once
//VerticalScroll.h
#ifndef _VERTICALSCROLL_H
#define _VERTICALSCROLL_H

#include "Scroll.h"
#include "OtherNoteForm.h"

class VerticalScroll : public Scroll {
public:
	VerticalScroll(OtherNoteForm *otherNoteForm);
	VerticalScroll(const VerticalScroll& source);
	virtual ~VerticalScroll();

	virtual void ScrollNextLine();
	virtual void ScrollPreviousLine();
	virtual void ScrollNextPage();
	virtual void ScrollPreviousPage();
	virtual void MoveThumb();
	VerticalScroll& operator=(const VerticalScroll& source);
};

#endif //_VERTICALSCROLL_H