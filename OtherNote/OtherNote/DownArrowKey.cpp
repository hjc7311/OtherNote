//DownArrowKey.cpp

#include "DownArrowKey.h"
#include "OtherNoteForm.h"

DownArrowKey::DownArrowKey(OtherNoteForm *otherNoteForm)
	:KeyAction(otherNoteForm) {

}

DownArrowKey::DownArrowKey(const DownArrowKey& source)
	: KeyAction(source) {

}

DownArrowKey::~DownArrowKey() {

}

DownArrowKey& DownArrowKey::operator=(const DownArrowKey& source) {
	KeyAction::operator=(source);

	return *this;
}

#include "Caret.h"
#include "Memo.h"
#include "Line.h"
#include "Character.h"
void DownArrowKey::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Memo *memo = this->otherNoteForm->GetMemo();

	Caret *caret = Caret::Instance(this->otherNoteForm);

	if (memo->GetRow() < memo->GetLength()) {
		Long originalXPosition = caret->GetXPosition();

		caret->MoveNextLine();
		memo->MoveNextRow();
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
		if (currentWidth - originalXPosition < originalXPosition - previousWidth) {
			resultWidth = currentWidth;
		}
		else {
			resultWidth = previousWidth;
		}

		caret->Move(resultWidth, caret->GetYPosition());
	}
}