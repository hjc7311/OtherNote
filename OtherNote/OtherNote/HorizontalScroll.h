// HorizontalScroll.h

#ifndef _HORIZONTALSCROLL_H
#define _HORIZONTALSCROLL_H

#include "Scroll.h"
#include "OtherNoteForm.h"

class HorizontalScroll : public Scroll {
public:
	HorizontalScroll(OtherNoteForm *otherNoteForm);
	HorizontalScroll(const HorizontalScroll& source);
	virtual ~HorizontalScroll();
	HorizontalScroll& operator=(const HorizontalScroll& source);
	virtual void ScrollNextLine();
	virtual void ScrollPreviousLine();
	virtual void ScrollNextPage();
	virtual void ScrollPreviousPage();
	virtual void MoveThumb();
	CScrollBar* GetScroll() const;
};

inline CScrollBar* HorizontalScroll::GetScroll() const {
	return const_cast<CScrollBar*>(this->scrollBar);
	//return Scroll::GetScroll();
}

#endif //_HORIZONTALSCROLL_H