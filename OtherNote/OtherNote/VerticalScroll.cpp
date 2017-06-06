//VerticalScroll.cpp

#include "VerticalScroll.h"
#include "CharacterFaces.h"
#include "Caret.h"

VerticalScroll::VerticalScroll(OtherNoteForm *otherNoteForm) 
	:Scroll(otherNoteForm){
	//1. scroll 생성
	CRect rect;
	this->otherNoteForm->GetClientRect(&rect);
	this->scrollBar->Create(SBS_VERT, CRect(rect.right - 20, rect.top, rect.right, rect.bottom - 20), this->otherNoteForm, 1);

	//2.캐럿 준비
	Caret *caret = Caret::Instance(0);
	
	//3. 캐릭터페이스 준비
	CharacterFaces *characterFaces = CharacterFaces::Instance(0);
	//Long tabWidth = characterFaces->GetCharacterSize(97).GetWidth();
	
	//4. scroll 준비
	SCROLLINFO scrinfo;
	scrinfo.cbSize = sizeof(scrinfo);
	scrinfo.fMask = SIF_ALL;
	scrinfo.nMin = 0;
	scrinfo.nMax = rect.bottom - 20;//this->maxLineSize;//(rect.right / (characterFaces->GetCharacterSize(97).GetWidth())) - 1;	
	scrinfo.nPage = rect.bottom - 20;//this ->maxLineSize / rect.right; //5;
	scrinfo.nPos = 0;
	this->scrollBar->SetScrollInfo(&scrinfo);
	this->scrollBar->ShowScrollBar(SB_BOTH);
	this->scrollBar->EnableScrollBar(ESB_DISABLE_BOTH);
}

VerticalScroll::VerticalScroll(const VerticalScroll& source)
	:Scroll(source) {
}

VerticalScroll::~VerticalScroll() {

}

VerticalScroll& VerticalScroll::operator=(const VerticalScroll& source) {
	//
	Scroll::operator=(source);
	return *this;
}

#include "OtherNoteForm.h"
#include "Line.h"
#include "Memo.h"
#include "Character.h"
void VerticalScroll::UpdateLine() {
	Memo *memo = this->otherNoteForm->GetMemo();
	CharacterFaces *characterFaces = CharacterFaces::Instance(0);
	Long height = characterFaces->GetCharacterSize(97).GetHeight();
	this->maxLineSize = memo->GetLength() * height;

	CRect rect;
	this->otherNoteForm->GetClientRect(&rect);
	if (this->GetMaxLineSize() > rect.bottom - 20) {
		SCROLLINFO scrinfo;
		this->scrollBar->GetScrollInfo(&scrinfo);
		scrinfo.nMax = this->maxLineSize;
		scrinfo.nPage = rect.bottom - 20;
		this->scrollBar->SetScrollInfo(&scrinfo);
	}
	else {
		this->SetScrollUnVisible();
	}
}

void VerticalScroll::ScrollNextLine() {
	SCROLLINFO  scrinfo;
	this->scrollBar->GetScrollInfo(&scrinfo);

	if ((scrinfo.nPos + scrinfo.nPage) < scrinfo.nMax) {
		CharacterFaces *characterFaces = CharacterFaces::Instance(0);
		Long height = characterFaces->GetCharacterSize(97).GetHeight();
		scrinfo.nPos += height;
		if (scrinfo.nPos + scrinfo.nPage > scrinfo.nMax) {
			scrinfo.nPos -= height;
			height -= scrinfo.nPos + scrinfo.nPage - scrinfo.nMax + height;
			scrinfo.nPos += height;
		}
		this->scrollBar->SetScrollInfo(&scrinfo);
		CRect rect;
		this->otherNoteForm->GetClientRect(&rect);
		this->otherNoteForm->ScrollWindow(0, -height, CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20), CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20));
		this->otherNoteForm->UpdateWindow();
	}
}

void VerticalScroll::ScrollPreviousLine() {
	SCROLLINFO  scrinfo;
	this->scrollBar->GetScrollInfo(&scrinfo);

	if (scrinfo.nPos > 0) {
		CharacterFaces *characterFaces = CharacterFaces::Instance(0);
		Long height = characterFaces->GetCharacterSize(97).GetHeight();
		scrinfo.nPos -= height;
		if (scrinfo.nPos < 0) {
			scrinfo.nPos += height;
			height = scrinfo.nPos;
			scrinfo.nPos -= height;//=0
		}
		this->scrollBar->SetScrollInfo(&scrinfo);
		CRect rect;
		this->otherNoteForm->GetClientRect(&rect);
		this->otherNoteForm->ScrollWindow(0, height, CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20), CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20));
		this->otherNoteForm->UpdateWindow();
	}
}

void VerticalScroll::ScrollNextPage() {
	SCROLLINFO  scrinfo;
	this->scrollBar->GetScrollInfo(&scrinfo);
	Long height = scrinfo.nPage;
	if ((scrinfo.nPos + scrinfo.nPage) < scrinfo.nMax) {
		CharacterFaces *characterFaces = CharacterFaces::Instance(0);
		scrinfo.nPos += scrinfo.nPage;
		if (scrinfo.nPos + scrinfo.nPage > scrinfo.nMax) {
			scrinfo.nPos -= scrinfo.nPage;
			height = scrinfo.nPage;
			height -= scrinfo.nPos + scrinfo.nPage - scrinfo.nMax + height;
			scrinfo.nPos += height;
		}
		this->scrollBar->SetScrollInfo(&scrinfo);
		CRect rect;
		this->otherNoteForm->GetClientRect(&rect);
		this->otherNoteForm->ScrollWindow(0, -height, CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20), CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20));
		this->otherNoteForm->UpdateWindow();
	}
}

void VerticalScroll::ScrollPreviousPage() {
	SCROLLINFO  scrinfo;
	this->scrollBar->GetScrollInfo(&scrinfo);
	Long height = scrinfo.nPage;
	if (scrinfo.nPos > 0) {
		CharacterFaces *characterFaces = CharacterFaces::Instance(0);
		scrinfo.nPos -= height;
		if (scrinfo.nPos < 0) {
			scrinfo.nPos += height;
			height = scrinfo.nPos;
			scrinfo.nPos = 0;
		}
		this->scrollBar->SetScrollInfo(&scrinfo);
		CRect rect;
		this->otherNoteForm->GetClientRect(&rect);
		this->otherNoteForm->ScrollWindow(0, height, CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20), CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20));
		this->otherNoteForm->UpdateWindow();
	}
}

void VerticalScroll::MoveThumb() {
	SCROLLINFO  scrinfo;
	this->scrollBar->GetScrollInfo(&scrinfo);
	Long height = scrinfo.nTrackPos - scrinfo.nPos;
	scrinfo.nPos = scrinfo.nTrackPos;
	this->scrollBar->SetScrollInfo(&scrinfo);

	CRect rect;
	this->otherNoteForm->GetClientRect(&rect);
	this->otherNoteForm->ScrollWindow(0, -height, CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20), CRect(rect.left, rect.top, rect.right - 20, rect.bottom - 20));
	this->otherNoteForm->UpdateWindow();
}

void VerticalScroll::ScrollPrevious(Long size) {

}

void VerticalScroll::ScrollNext(Long size) {

}