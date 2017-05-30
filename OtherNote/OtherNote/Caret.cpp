//Caret.cpp

#include "Caret.h"
#include "OtherNoteForm.h"
#include "Memo.h"
#include "Line.h"
#include "Character.h"
#include "CharacterFaces.h"
#include "CharacterSize.h"

Caret* Caret::_instance = 0;

Caret::Caret(OtherNoteForm *otherNoteForm) {
	this->otherNoteForm = otherNoteForm;
	
	CharacterFaces *characterFaces = CharacterFaces::Instance(0);
	CharacterSize characterSize = characterFaces->GetCharacterSize(127);
	
	this->width = 2;
	this->height = characterSize.GetHeight();
	this->otherNoteForm->CWnd::CreateSolidCaret(this->width, this->height);
	
	this->xPosition = 0;
	this->yPosition = 0;
	this->otherNoteForm->CWnd::SetCaretPos(CPoint(xPosition, yPosition));
	
	this->otherNoteForm->CWnd::ShowCaret();
}

Caret::Caret(const Caret& source) {
	this->otherNoteForm = source.otherNoteForm;
	this->width = source.width;
	this->height = source.height;
	this->xPosition = source.xPosition;
	this->yPosition = source.yPosition;
}

Caret::~Caret() {
	_instance = 0;
}

Caret& Caret::operator=(const Caret& source) {
	this->otherNoteForm = source.otherNoteForm;
	this->width = source.width;
	this->height = source.height;
	this->xPosition = source.xPosition;
	this->yPosition = source.yPosition;

	return *this;
}

Caret* Caret::Instance(OtherNoteForm *otherNoteForm) {
	if (_instance == 0) {
		_instance = new Caret(otherNoteForm);
	}

	return _instance;
}

void Caret::Move(Long xPosition, Long yPosition) {
	this->xPosition = xPosition;
	this->yPosition = yPosition;

	CWnd::SetCaretPos(CPoint(this->xPosition, this->yPosition));
}

void Caret::MovePreviousCharacter() {
	Memo *memo = this->otherNoteForm->GetMemo();
	Line *line = memo->GetLine(memo->GetRow());
	Character *character = line->GetCharacter(line->GetColumn() - 1);
	
	Long moveWidth = character->GetWidth();
	this->xPosition -= moveWidth;

	CWnd::SetCaretPos(CPoint(this->xPosition, this->yPosition));
}

void Caret::MoveNextCharacter() {
	Memo *memo = this->otherNoteForm->GetMemo();
	Line *line = memo->GetLine(memo->GetRow());
	Character *character = line->GetCharacter(line->GetColumn() - 1);

	Long moveWidth = character->GetWidth();
	this->xPosition += moveWidth;

	CWnd::SetCaretPos(CPoint(this->xPosition, this->yPosition));
}

void Caret::MovePreviousLine() {
	this->xPosition = 0;
	this->yPosition -= this->height;

	CWnd::SetCaretPos(CPoint(this->xPosition, this->yPosition));
}

void Caret::MoveNextLine() {
	this->xPosition = 0;
	this->yPosition += this->height;

	CWnd::SetCaretPos(CPoint(this->xPosition, this->yPosition));
}

void Caret::MovePreviousTab() {
	CharacterFaces *characterFaces = CharacterFaces::Instance(0);
	Long tabWidth = characterFaces->GetCharacterSize(97).GetWidth() * 8;

	Long moveWidth = this->xPosition%tabWidth;
	this->xPosition -= moveWidth;

	CWnd::SetCaretPos(CPoint(this->xPosition, this->yPosition));
}

void Caret::MoveNextTab() {
	CharacterFaces *characterFaces = CharacterFaces::Instance(0);
	Long tabWidth = characterFaces->GetCharacterSize(97).GetWidth() * 8;

	Long moveWidth = tabWidth - (this->xPosition%tabWidth);
	this->xPosition += moveWidth;

	CWnd::SetCaretPos(CPoint(this->xPosition, this->yPosition));
}

bool Caret::ChangeCaret() {
	DestroyCaret();

	CharacterFaces *characterFaces = CharacterFaces::Instance(0);
	this->width = 2;
	this->height = characterFaces->GetCharacterSize(127).GetHeight();

	otherNoteForm->CWnd::CreateSolidCaret(this->width, this->height);

	otherNoteForm->CWnd::ShowCaret();

	return true;
}

bool Caret::ChangeImeCaret() {
	DestroyCaret();
	
	CharacterFaces *characterFaces = CharacterFaces::Instance(0);
	this->width = characterFaces->GetCharacterSize(127).GetWidth();
	this->height = characterFaces->GetCharacterSize(127).GetHeight();

	otherNoteForm->CWnd::CreateSolidCaret(this->width, this->height);

	otherNoteForm->CWnd::ShowCaret();

	return true;
}

//void SetCaretPosition(NoteBookForm *noteBookForm, Long xPosition, Long yPosition) {
////	noteBookForm->CreateSolidCaret(5, 50);
//
//	noteBookForm->SetCaretPos(*(noteBookForm->point));
//
//	//noteBookForm->ShowCaret();
//}