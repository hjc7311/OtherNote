//VerticalScroll.cpp

#include "VerticalScroll.h"
#include "CharacterFaces.h"

VerticalScroll::VerticalScroll(OtherNoteForm *otherNoteForm) 
	:Scroll(otherNoteForm){
	//1. scroll 생성
	CRect rect;
	this->otherNoteForm->GetClientRect(&rect);
	this->scrollBar->Create(SBS_VERT, CRect(rect.right-20, rect.top, rect.right, rect.bottom - 20), this->otherNoteForm, 1);

	//2. CharacterFaces 준비
	CharacterFaces *characterFaces = CharacterFaces::Instance(0);

	//3. SCROLLIINFO 준비
	SCROLLINFO scrollInfo;
	scrollInfo.cbSize = sizeof(scrollInfo);
	scrollInfo.fMask = SIF_ALL;
	scrollInfo.nMin = 0;
	scrollInfo.nMax = (rect.bottom / (characterFaces->GetCharacterSize(97).GetHeight())) - 1;
	scrollInfo.nPage = 5;
	scrollInfo.nPos = 0;
	scrollBar->SetScrollInfo(&scrollInfo);
	scrollBar->ShowScrollBar(SB_VERT);
}

VerticalScroll::VerticalScroll(const VerticalScroll& source)
	:Scroll(source) {
}

VerticalScroll::~VerticalScroll() {

}

void VerticalScroll::ScrollNextLine() {

}

void VerticalScroll::ScrollPreviousLine() {

}

void VerticalScroll::ScrollNextPage() {

}

void VerticalScroll::ScrollPreviousPage() {

}

void VerticalScroll::MoveThumb() {

}

VerticalScroll& VerticalScroll::operator=(const VerticalScroll& source) {
	//
	Scroll::operator=(source);
	return *this;
}