//UpArrowKey.cpp

#include "UpArrowKey.h"
#include "OtherNoteForm.h"

UpArrowKey::UpArrowKey(OtherNoteForm *otherNoteForm)
	:KeyAction(otherNoteForm) {

}

UpArrowKey::UpArrowKey(const UpArrowKey& source)
	: KeyAction(source) {

}

UpArrowKey::~UpArrowKey() {

}

UpArrowKey& UpArrowKey::operator=(const UpArrowKey& source) {
	KeyAction::operator=(source);

	return *this;
}

#include "Caret.h"
#include "Memo.h"
#include "Line.h"
#include "Character.h"
void UpArrowKey::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
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
		if (currentWidth - originalXPosition < originalXPosition - previousWidth) {
			resultWidth = currentWidth;
		}
		else {
			resultWidth = previousWidth;
		}

		caret->Move(resultWidth, caret->GetYPosition());
	}
}