//ShiftDownArrowKey.cpp

#include "ShiftDownArrowKey.h"
#include "OtherNoteForm.h"

ShiftDownArrowKey::ShiftDownArrowKey(OtherNoteForm *otherNoteForm)
	:KeyAction(otherNoteForm) {

}

ShiftDownArrowKey::ShiftDownArrowKey(const ShiftDownArrowKey& source)
	: KeyAction(source) {

}

ShiftDownArrowKey::~ShiftDownArrowKey() {

}

ShiftDownArrowKey& ShiftDownArrowKey::operator=(const ShiftDownArrowKey& source) {
	KeyAction::operator=(source);

	return *this;
}

#include "Caret.h"
#include "Memo.h"
#include "Line.h"
#include "Character.h"
void ShiftDownArrowKey::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Memo *memo = this->otherNoteForm->GetMemo();

	Caret *caret = Caret::Instance(this->otherNoteForm);

	if (memo->GetRow() < memo->GetLength() - 1) {
		Long originalXPosition = caret->GetXPosition();

		caret->MoveNextLine();
		memo->MoveNextRow();
		Line *line = memo->GetLine(memo->GetRow());
		line->MoveFirstColumn();

		Long previousWidth = 0;
		Long currentWidth = 0;
		while (currentWidth < originalXPosition && line->GetColumn() < line->GetLength()) {
			previousWidth = currentWidth;
			currentWidth += line->GetCharacter(line->GetColumn())->GetWidth();
			line->MoveNextColumn();
		}

		Long resultWidth;
		if (currentWidth - originalXPosition <= originalXPosition - previousWidth) {
			resultWidth = currentWidth;
		}
		else {
			resultWidth = previousWidth;
			line->MovePreviousColumn();
		}

		caret->Move(resultWidth, caret->GetYPosition());
	}
}