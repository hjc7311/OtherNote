//ShiftUpArrowKey.cpp

#include "ShiftUpArrowKey.h"
#include "OtherNoteForm.h"

ShiftUpArrowKey::ShiftUpArrowKey(OtherNoteForm *otherNoteForm)
	:KeyAction(otherNoteForm) {

}

ShiftUpArrowKey::ShiftUpArrowKey(const ShiftUpArrowKey& source)
	: KeyAction(source) {

}

ShiftUpArrowKey::~ShiftUpArrowKey() {

}

ShiftUpArrowKey& ShiftUpArrowKey::operator=(const ShiftUpArrowKey& source) {
	KeyAction::operator=(source);

	return *this;
}

#include "Caret.h"
#include "Memo.h"
#include "Line.h"
#include "Character.h"
void ShiftUpArrowKey::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Memo *memo = this->otherNoteForm->GetMemo();

	Caret *caret = Caret::Instance(this->otherNoteForm);

	if (memo->GetRow() > 0) {
		Long originalXPosition = caret->GetXPosition();

		caret->MovePreviousLine();
		memo->MovePreviousRow();

		Line *line = memo->GetLine(memo->GetRow());
		line->MoveFirstColumn();

		//Long previousWidth = -1;
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