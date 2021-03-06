//RightArrowKey.cpp

#include "RightArrowKey.h"
#include "OtherNoteForm.h"

RightArrowKey::RightArrowKey(OtherNoteForm *otherNoteForm)
	:KeyAction(otherNoteForm) {

}

RightArrowKey::RightArrowKey(const RightArrowKey& source)
	: KeyAction(source) {

}

RightArrowKey::~RightArrowKey() {

}

RightArrowKey& RightArrowKey::operator=(const RightArrowKey& source) {
	KeyAction::operator=(source);

	return *this;
}

#include "Caret.h"
#include "Memo.h"
#include "Line.h"
void RightArrowKey::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Memo *memo = this->otherNoteForm->GetMemo();
	Line *line = memo->GetLine(memo->GetRow());

	Caret *caret = Caret::Instance(this->otherNoteForm);

	if (memo->GetRow() < memo->GetLength()-1 || line->GetColumn() < line->GetLength()) {
		if (line->GetColumn() < line->GetLength()) {
			line->MoveNextColumn();
			caret->MoveNextCharacter();
		}
		else if (line->GetColumn() == line->GetLength()) {
			memo->MoveNextRow();
			line = memo->GetLine(memo->GetRow());
			line->MoveFirstColumn();
			caret->MoveNextLine();
		}
	}
}