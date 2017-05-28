//Caret.cpp

#include "Caret.h"
#include "NoteBookForm.h"
#include "Memo.h"
#include "Line.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
#include "CharacterFaces.h"
#include "CharacterSize.h"

Caret* Caret::_instance = 0;
//NoteBookForm* Caret::noteBookFormLink = 0;
//Long Caret::width = 0;
//Long Caret::height = 0;
//Long Caret::xPosition = 0;
//Long Caret::yPosition = 0;

Caret::Caret(NoteBookForm *noteBookForm) {
	this->noteBookFormLink = noteBookForm;
	
	CharacterFaces *characterFaces = CharacterFaces::Instance(this->noteBookFormLink->GetDC());
	CharacterSize characterSize = characterFaces->GetCharacterSize(127);
	
	this->width = 2;
	this->height = characterSize.GetHeight();
	this->noteBookFormLink->CWnd::CreateSolidCaret(this->width, this->height);
	//this->noteBookFormLink->CWnd::CreateSolidCaret(2, 80);

	this->xPosition = 0;
	this->yPosition = 0;
	this->noteBookFormLink->CWnd::SetCaretPos(CPoint(xPosition, yPosition));
	
	this->noteBookFormLink->CWnd::ShowCaret();
}

Caret::~Caret() {
	_instance = 0;
}

Caret* Caret::Instance(NoteBookForm *noteBookForm) {
	if (_instance == 0) {
		_instance = new Caret(noteBookForm);
	}

	return _instance;
}

//void SetCaretPosition(NoteBookForm *noteBookForm, Long xPosition, Long yPosition) {
////	noteBookForm->CreateSolidCaret(5, 50);
//
//	noteBookForm->SetCaretPos(*(noteBookForm->point));
//
//	//noteBookForm->ShowCaret();
//}

void Caret::Move(Long xPos, Long yPos) {
	this->xPosition = xPos;
	this->yPosition = yPos;

	CWnd::SetCaretPos(CPoint(xPosition, yPosition));

}

void Caret::MoveNextCharacter() {
	Memo *memo = this->noteBookFormLink->GetMemo();
	Line *line = memo->GetLine(memo->GetRow());
	Character *character = line->GetCharacter(line->GetColumn() - 1);
	Long moveWidth;

	//if (dynamic_cast<SingleCharacter*>(character)) {
	//	char value = dynamic_cast<SingleCharacter*>(character)->GetValue();
	//	if (value == '\t') {
	//		CharacterFaces *characterFaces = CharacterFaces::Instance(noteBookFormLink->GetDC());
	//		Long tabWidth = characterFaces->GetCharacterSize(97).GetWidth() * 8;	//ASCII a:97
	//		moveWidth = tabWidth - (xPosition%tabWidth);
	//	}
	//	else {
	//		moveWidth = character->GetWidth();
	//	}
	//}
	//else if (dynamic_cast<DoubleCharacter*>(character)) {
	moveWidth = character->GetWidth();
//	}

	this->xPosition += moveWidth;

	CWnd::SetCaretPos(CPoint(xPosition, yPosition));
}

void Caret::MovePreviousCharacter() {
	Memo *memo = this->noteBookFormLink->GetMemo();
	Line *line = memo->GetLine(memo->GetRow());
	Character *character = line->GetCharacter(line->GetColumn() - 1);
	Long moveWidth = character->GetWidth();

	this->xPosition -= moveWidth;

	CWnd::SetCaretPos(CPoint(xPosition, yPosition));
}

void Caret::MoveNextLine() {
	/*Memo *memo = this->noteBookFormLink->GetMemo();
	Line *line = memo->GetLine(memo->GetRow() - 1);
	Character *character = line->GetCharacter(line->GetColumn() - 1);
	Long moveHeight = character->GetHeight();*/

	this->yPosition += this->height;
	this->xPosition = 0;
	//line = memo->GetLine(memo->GetRow());
	//Long moveWidth;
	//xPosition = 0;
	//Long i = 0;
	//while (i < line->GetColumn()) {
	//	character = line->GetCharacter(line->GetColumn());
	//	moveWidth = character->GetWidth();
	//	xPosition += moveWidth;
	//	i++;
	//}


	CWnd::SetCaretPos(CPoint(xPosition, yPosition));
}

void Caret::MovePreviousLine() {
	Memo *memo = this->noteBookFormLink->GetMemo();
	Line *line = memo->GetLine(memo->GetRow());
	
	//Character *character = line->GetCharacter(line->GetColumn() - 1);
	//Long moveHeight = character->GetHeight();

//	yPosition -= moveHeight;
	this->xPosition = 0;
	this->yPosition -= height;
	/*
	line = memo->GetLine(memo->GetRow() - 1);
	Long moveWidth;
	xPosition = 0;
	Long i = 0;
	while (i < line->GetColumn()) {
		character = line->GetCharacter(line->GetColumn());
		moveWidth = character->GetWidth();
		xPosition += moveWidth;
		i++;
	}
	*/
	CWnd::SetCaretPos(CPoint(xPosition, yPosition));
}

bool Caret::ChangeImeCaret() {
	DestroyCaret();

	//Memo *memo = noteBookFormLink->GetMemo();
	//Line *line = memo->GetLine(memo->GetRow());
	//Character *character = line->GetCharacter(line->GetColumn()-1);
	//
	//width = character->GetWidth();
	//height = character->GetHeight();

	CharacterFaces *characterFaces = CharacterFaces::Instance(this->noteBookFormLink->GetDC());
	//CharacterSize characterSize(characterFaces->GetCharacterSize(127));
	//width = characterSize.GetWidth();
	//height = characterSize.GetHeight();

	this->width = characterFaces->GetCharacterSize(127).GetWidth();
	this->height = characterFaces->GetCharacterSize(127).GetHeight();

	noteBookFormLink->CWnd::CreateSolidCaret(this->width, this->height);

	noteBookFormLink->CWnd::ShowCaret();

	return true;
}

bool Caret::ChangeCaret() {
	DestroyCaret();

	Memo *memo = noteBookFormLink->GetMemo();
	Line *line = memo->GetLine(memo->GetRow());
	Character *character = line->GetCharacter(line->GetColumn() - 1);

	width = 2;
	height = character->GetHeight();

	noteBookFormLink->CWnd::CreateSolidCaret(width, height);

	noteBookFormLink->CWnd::ShowCaret();

	return true;
}

void Caret::MoveNextTab() {
	CharacterFaces *characterFaces = CharacterFaces::Instance(noteBookFormLink->GetDC());

	Long tabWidth = characterFaces->GetCharacterSize(97).GetWidth()*8;

	Long moveWidth = tabWidth - (xPosition%tabWidth);
	xPosition += moveWidth;

	CWnd::SetCaretPos(CPoint(xPosition, yPosition));
}

void Caret::MovePreviousTab() {

}