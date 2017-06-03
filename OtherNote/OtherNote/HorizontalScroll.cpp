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
	scrinfo.nMax = (rect.right / (characterFaces->GetCharacterSize(97).GetWidth())) - 1;
	scrinfo.nPage = 5;
	scrinfo.nPos = 0;
	this->scrollBar->SetScrollInfo(&scrinfo); 
	this->scrollBar->ShowScrollBar(SB_BOTH);
}

HorizontalScroll::HorizontalScroll(const HorizontalScroll& source)
	:Scroll(source) {
}

HorizontalScroll::~HorizontalScroll() {
}

HorizontalScroll& HorizontalScroll::operator=(const HorizontalScroll& source) {
	return *this;
}

void HorizontalScroll::ScrollNextLine() {
	SCROLLINFO  scrinfo;
	this->scrollBar->GetScrollInfo(&scrinfo);
	if(scrinfo.nPos+4 != scrinfo.nMax) {
		scrinfo.nPos += 1;
		this->scrollBar->SetScrollInfo(&scrinfo);
		CharacterFaces *characterFaces = CharacterFaces::Instance(0);
		Long width = characterFaces->GetCharacterSize(97).GetWidth();
		CRect rect;
		this->otherNoteForm->GetClientRect(&rect);
		this->otherNoteForm->ScrollWindow(-width, 0, CRect(rect.left, rect.top, rect.right-20, rect.bottom-20), NULL);
		//this->otherNoteForm->ScrollWindow(-width, 0, NULL, NULL);
		this->otherNoteForm->UpdateWindow();
	}
}

void HorizontalScroll::ScrollPreviousLine() {
}

void HorizontalScroll::ScrollNextPage() {
}

void HorizontalScroll::ScrollPreviousPage() {
}

void HorizontalScroll::MoveThumb() {
}