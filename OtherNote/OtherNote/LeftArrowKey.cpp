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

	if (line->GetColumn() > 0) {
		caret->MovePreviousCharacter();
		line->MovePreviousColumn();
	}
}