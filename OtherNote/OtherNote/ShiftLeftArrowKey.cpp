//ShiftLeftArrowKey.cpp

#include "ShiftLeftArrowKey.h"
#include "OtherNoteForm.h"

ShiftLeftArrowKey::ShiftLeftArrowKey(OtherNoteForm *otherNoteForm)
	:KeyAction(otherNoteForm) {

}

ShiftLeftArrowKey::ShiftLeftArrowKey(const ShiftLeftArrowKey& source)
	: KeyAction(source) {

}

ShiftLeftArrowKey::~ShiftLeftArrowKey() {

}

ShiftLeftArrowKey& ShiftLeftArrowKey::operator=(const ShiftLeftArrowKey& source) {
	KeyAction::operator=(source);

	return *this;
}

#include "Caret.h"
#include "Memo.h"
#include "Line.h"
#include "Character.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
void ShiftLeftArrowKey::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Memo *memo = this->otherNoteForm->GetMemo();
	Line *line = memo->GetLine(memo->GetRow());

	Caret *caret = Caret::Instance(this->otherNoteForm);

	if (memo->GetRow() > 0 || line->GetColumn() > 0) {
		if (line->GetColumn() > 0) {
			caret->MovePreviousCharacter();
			line->MovePreviousColumn();
		}
		else if (line->GetColumn() == 0) {
			caret->MovePreviousLine();

			memo->MovePreviousRow();
			line = memo->GetLine(memo->GetRow());

			line->MoveLastColumn();
			caret->MoveLastCharacter();
		}
	}
}