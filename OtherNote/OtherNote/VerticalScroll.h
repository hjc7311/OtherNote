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
	VerticalScroll& operator=(const VerticalScroll& source);
	virtual void UpdateLine();
	virtual void ScrollNextLine();
	virtual void ScrollPreviousLine();
	virtual void ScrollNextPage();
	virtual void ScrollPreviousPage();
	virtual void MoveThumb();
	virtual void SetScrollVisible();
	virtual void SetScrollUnVisible();
	virtual void ScrollPreviousByCaret();
	virtual void ScrollNextByCaret();
};

#endif //_VERTICALSCROLL_H