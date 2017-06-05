// HorizontalScroll.cpp

#include "HorizontalScroll.h"
#include "Caret.h"
#include "CharacterFaces.h"

HorizontalScroll::HorizontalScroll(OtherNoteForm *otherNoteForm)
	:Scroll(otherNoteForm) {
	CRect rect;
	this->otherNoteForm->GetClientRect(&rect);
	this->scrollBar->Create(SBS_HORZ, CRect(rect.left, rect.bottom-20, rect.right-20, rect.bottom), this->otherNoteForm, 1);
	Caret *caret = Caret::Instance(0);
	CharacterFaces *characterFaces = CharacterFaces::Instance(0);
	//Long tabWidth = characterFaces->GetCharacterSize(97).GetWidth();
	SCROLLINFO scrinfo;
	scrinfo.cbSize = sizeof(scrinfo); 
	scrinfo.fMask = SIF_ALL; 
	scrinfo.nMin = 0;
	scrinfo.nMax = rect.right - 20;//this->maxLineSize;//(rect.right / (characterFaces->GetCharacterSize(97).GetWidth())) - 1;	
	scrinfo.nPage = rect.right - 20;//this ->maxLineSize / rect.right; //5;
	scrinfo.nPos = 0;
	this->scrollBar->SetScrollInfo(&scrinfo); 
	this->scrollBar->ShowScrollBar(SB_BOTH);
	this->scrollBar->EnableScrollBar(ESB_DISABLE_BOTH);
}

HorizontalScroll::HorizontalScroll(const HorizontalScroll& source)
	:Scroll(source) {
}

HorizontalScroll::~HorizontalScroll() {
}

HorizontalScroll& HorizontalScroll::operator=(const HorizontalScroll& source) {
	return *this;
}

#include "OtherNoteForm.h"
#include "Line.h"
#include "Memo.h"
#include "Character.h"
void HorizontalScroll::UpdateLine() {
	Memo *memo = this->otherNoteForm->GetMemo();
	Line *line;// = memo->GetLine(memo->GetRow());
	Long lineWidth;// = 0;
	Long i = 0;
	Long j;
	this->maxLineSize = 0;
	while (i < memo->GetLength()) {
		line = memo->GetLine(i);
		j = 0;
		lineWidth = 0;
		while (j < line->GetLength()) {
			lineWidth += line->GetCharacter(j)->GetWidth();
			j++;
		}
		if (this->maxLineSize < lineWidth) {
			this->maxLineSize = lineWidth;
		}
		i++;
	}
	CRect rect;
	this->otherNoteForm->GetClientRect(&rect);
	if (this->GetMaxLineSize() > rect.right - 20) {
		SCROLLINFO scrinfo;
		this->scrollBar->GetScrollInfo(&scrinfo);
		scrinfo.nMax = this->maxLineSize;
		scrinfo.nPage = rect.right - 20;
		this->scrollBar->SetScrollInfo(&scrinfo);
	}
}

void HorizontalScroll::ScrollNextLine() {
	SCROLLINFO  scrinfo;
	this->scrollBar->GetScrollInfo(&scrinfo);

	if((scrinfo.nPos + scrinfo.nPage) < scrinfo.nMax) {
		CharacterFaces *characterFaces = CharacterFaces::Instance(0);
		Long width = characterFaces->GetCharacterSize(97).GetWidth();
		scrinfo.nPos += width;
		if (scrinfo.nPos + scrinfo.nPage > scrinfo.nMax) {
			scrinfo.nPos -= width;
			width -= scrinfo.nPos + scrinfo.nPage - scrinfo.nMax + width;
			scrinfo.nPos += width;
		}		
		this->scrollBar->SetScrollInfo(&scrinfo);
		CRect rect;
		this->otherNoteForm->GetClientRect(&rect);
		this->otherNoteForm->ScrollWindow(-width, 0, CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20), CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20));
		this->otherNoteForm->UpdateWindow();
	}
}

void HorizontalScroll::ScrollPreviousLine() {
	SCROLLINFO  scrinfo;
	this->scrollBar->GetScrollInfo(&scrinfo);

	if (scrinfo.nPos > 0) {
		CharacterFaces *characterFaces = CharacterFaces::Instance(0);
		Long width = characterFaces->GetCharacterSize(97).GetWidth();
		scrinfo.nPos -= width;
		if (scrinfo.nPos < 0) {
			scrinfo.nPos += width;
			width = scrinfo.nPos;
			scrinfo.nPos = 0;
		}
		this->scrollBar->SetScrollInfo(&scrinfo);
		CRect rect;
		this->otherNoteForm->GetClientRect(&rect);
		this->otherNoteForm->ScrollWindow(+width, 0, CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20), CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20));
		this->otherNoteForm->UpdateWindow();
	}
}

void HorizontalScroll::ScrollNextPage() {
	SCROLLINFO  scrinfo;
	this->scrollBar->GetScrollInfo(&scrinfo);
	Long width = scrinfo.nPage;
	if ((scrinfo.nPos + scrinfo.nPage) < scrinfo.nMax) {
		CharacterFaces *characterFaces = CharacterFaces::Instance(0);
		scrinfo.nPos += scrinfo.nPage;
		if (scrinfo.nPos + scrinfo.nPage > scrinfo.nMax) {
			scrinfo.nPos -= scrinfo.nPage;
			width = scrinfo.nPage;
			width -= scrinfo.nPos + scrinfo.nPage - scrinfo.nMax + width;
			scrinfo.nPos += width;
		}
		this->scrollBar->SetScrollInfo(&scrinfo);
		CRect rect;
		this->otherNoteForm->GetClientRect(&rect);
		this->otherNoteForm->ScrollWindow(-width, 0, CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20), CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20));
		this->otherNoteForm->UpdateWindow();
	}
}

void HorizontalScroll::ScrollPreviousPage() {
	SCROLLINFO  scrinfo;
	this->scrollBar->GetScrollInfo(&scrinfo);
	Long width = scrinfo.nPage;
	if (scrinfo.nPos > 0) {
		CharacterFaces *characterFaces = CharacterFaces::Instance(0);
		scrinfo.nPos -= width;
		if (scrinfo.nPos < 0) {
			scrinfo.nPos += width;
			width = scrinfo.nPos;
			scrinfo.nPos = 0;
		}
		this->scrollBar->SetScrollInfo(&scrinfo);
		CRect rect;
		this->otherNoteForm->GetClientRect(&rect);
		this->otherNoteForm->ScrollWindow(+width, 0, CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20), CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20));
		this->otherNoteForm->UpdateWindow();
	}
}

void HorizontalScroll::MoveThumb() {
	SCROLLINFO  scrinfo;
	this->scrollBar->GetScrollInfo(&scrinfo);
	Long width = scrinfo.nTrackPos - scrinfo.nPos;
	scrinfo.nPos = scrinfo.nTrackPos;
	this->scrollBar->SetScrollInfo(&scrinfo);

	CRect rect;
	this->otherNoteForm->GetClientRect(&rect);
	this->otherNoteForm->ScrollWindow(-width, 0, CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20), CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20));
	this->otherNoteForm->UpdateWindow();
}

void HorizontalScroll::SetScrollVisible() {
	this->scrollBar->EnableScrollBar(ESB_ENABLE_BOTH);
}

void HorizontalScroll::SetScrollUnVisible() {
	this->scrollBar->EnableScrollBar(ESB_DISABLE_BOTH);
}

void HorizontalScroll::ScrollNextByCaret() {
}

void HorizontalScroll::ScrollPreviousByCaret() {
}

