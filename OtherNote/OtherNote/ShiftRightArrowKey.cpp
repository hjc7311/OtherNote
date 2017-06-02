//ShiftRightArrowKey.cpp

#include "ShiftRightArrowKey.h"
#include "OtherNoteForm.h"

ShiftRightArrowKey::ShiftRightArrowKey(OtherNoteForm *otherNoteForm)
	:KeyAction(otherNoteForm) {

}

ShiftRightArrowKey::ShiftRightArrowKey(const ShiftRightArrowKey& source)
	: KeyAction(source) {

}

ShiftRightArrowKey::~ShiftRightArrowKey() {

}

ShiftRightArrowKey& ShiftRightArrowKey::operator=(const ShiftRightArrowKey& source) {
	KeyAction::operator=(source);

	return *this;
}

#include "Caret.h"
#include "Memo.h"
#include "Line.h"
#include "Character.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
void ShiftRightArrowKey::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Memo *memo = this->otherNoteForm->GetMemo();
	Line *line = memo->GetLine(memo->GetRow());

	Caret *caret = Caret::Instance(this->otherNoteForm);

	if (memo->GetRow() < memo->GetLength() - 1 || line->GetColumn() < line->GetLength()) {
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