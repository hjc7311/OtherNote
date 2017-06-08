//ReturnKey.cpp

#include "ReturnKey.h"
#include "OtherNoteForm.h"

ReturnKey::ReturnKey(OtherNoteForm *otherNoteForm)
	:KeyAction(otherNoteForm) {

}

ReturnKey::ReturnKey(const ReturnKey& source)
	: KeyAction(source) {

}

ReturnKey::~ReturnKey() {

}

ReturnKey& ReturnKey::operator=(const ReturnKey& source) {
	KeyAction::operator=(source);

	return *this;
}

#include "Caret.h"
#include "Memo.h"
#include "Line.h"
#include "Character.h"
#include "VerticalScroll.h"
#include "CharacterFaces.h"
void ReturnKey::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Memo *memo = this->otherNoteForm->GetMemo();
	Line *line = memo->GetLine(memo->GetRow());
		
	memo->InsertLine();
	Line *newLine = memo->GetLine(memo->GetRow());

	while (line->GetColumn() < line->GetLength()) {
		newLine->Add(line->GetCharacter(line->GetColumn())->Clone());
		newLine->MoveNextColumn();
		
		line->MoveNextColumn();
		line->Erase();
	}
	newLine->MoveFirstColumn();
	
	Caret *caret = Caret::Instance(this->otherNoteForm);
	caret->MoveNextLine();

	this->otherNoteForm->GetVerticalScroll()->UpdateLine();
	CharacterFaces *characterFaces = CharacterFaces::Instance(0);
	Long size = characterFaces->GetCharacterSize(97).GetHeight();
	this->otherNoteForm->GetVerticalScroll()->ScrollNext(size);
}