// Scroll.h
#ifndef _SCROLL_H
#define _SCROLL_H

#include "OtherNoteForm.h"

class Scroll {
public:
	Scroll(OtherNoteForm *otherNoteForm);
	Scroll(const Scroll& source);
	virtual ~Scroll() = 0;
	Scroll& operator=(const Scroll& source);
	virtual void ScrollNextLine() = 0;
	virtual void ScrollPreviousLine() = 0;
	virtual void ScrollNextPage() = 0;
	virtual void ScrollPreviousPage() = 0;
	virtual void MoveThumb() = 0;
	//CScrollBar* GetScroll() const;
protected:
	OtherNoteForm *otherNoteForm;
	CScrollBar *scrollBar;
};
//
//inline CScrollBar* Scroll::GetScroll() const {
//	return const_cast<CScrollBar*>(this->scrollBar);
//}

#endif //_SCROLL_H