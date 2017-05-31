//DeleteKey.cpp

#include "DeleteKey.h"
#include "OtherNoteForm.h"

DeleteKey::DeleteKey(OtherNoteForm *otherNoteForm) 
	:KeyAction(otherNoteForm){
}

DeleteKey::DeleteKey(const DeleteKey& source) 
	:KeyAction(source){
}

DeleteKey::~DeleteKey() {

}

DeleteKey& DeleteKey::operator=(const DeleteKey& source) {
	KeyAction::operator=(source);
	return *this;
}

#include "Memo.h"
#include "Line.h"
#include "Caret.h"

void DeleteKey::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Memo *memo = this->otherNoteForm->GetMemo();
	Line *line = memo->GetLine(memo->GetRow());

	Caret *caret = Caret::Instance(this->otherNoteForm);

	if (line->GetLength() != 0 && line->GetColumn() < line->GetLength()) {
		line->MoveNextColumn();
		line->Erase();
	}
	else if (memo->GetRow() != 0) {
		if (memo->GetLength() > 1) {
			memo->RemoveLine();
			//line->MovePreviousColumn();
			//caret->MovePreviousCharacter();
		}
	}
	this->otherNoteForm->RedrawWindow();
}