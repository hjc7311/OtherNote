//LeftArrowKey.cpp

#include "LeftArrowKey.h"
#include "OtherNoteForm.h"

LeftArrowKey::LeftArrowKey(OtherNoteForm *otherNoteForm)
	:KeyAction(otherNoteForm) {

}

LeftArrowKey::LeftArrowKey(const LeftArrowKey& source)
	: KeyAction(source) {

}

LeftArrowKey::~LeftArrowKey() {

}

LeftArrowKey& LeftArrowKey::operator=(const LeftArrowKey& source) {
	KeyAction::operator=(source);

	return *this;
}

#include "Caret.h"
#include "Memo.h"
#include "Line.h"
void LeftArrowKey::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
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