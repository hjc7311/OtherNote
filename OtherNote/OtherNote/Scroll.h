// Scroll.h
#ifndef _SCROLL_H
#define _SCROLL_H

#include "OtherNoteForm.h"
typedef signed long int Long;

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
	virtual void SetScrollVisible();
	virtual void SetScrollUnVisible();
	virtual void UpdateLine() = 0;
	virtual void ScrollPrevious(Long size) = 0;
	virtual void ScrollNext(Long size) = 0;

	OtherNoteForm* GetOtherNoteForm() const;
	CScrollBar* GetScrollBar() const;
	Long GetMaxLineSize() const;

protected:
	OtherNoteForm *otherNoteForm;
	CScrollBar *scrollBar;
	Long maxLineSize;
};

inline OtherNoteForm* Scroll::GetOtherNoteForm() const {
	return const_cast<OtherNoteForm*>(this->otherNoteForm);
}

inline CScrollBar* Scroll::GetScrollBar() const {
	return const_cast<CScrollBar*>(this->scrollBar);
}

inline Long Scroll::GetMaxLineSize() const {
	return this->maxLineSize;
}

#endif //_SCROLL_H