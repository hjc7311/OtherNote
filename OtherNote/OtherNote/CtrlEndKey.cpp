//CtrlEndKey.cpp

#include "CtrlEndKey.h"
#include "OtherNoteForm.h"

CtrlEndKey::CtrlEndKey(OtherNoteForm *otherNoteForm)
	:KeyAction(otherNoteForm) {

}

CtrlEndKey::CtrlEndKey(const CtrlEndKey& source)
	: KeyAction(source) {

}

CtrlEndKey::~CtrlEndKey() {

}

CtrlEndKey& CtrlEndKey::operator=(const CtrlEndKey& source) {
	KeyAction::operator=(source);

	return *this;
}

#include "Caret.h"
#include "Memo.h"
#include "Line.h"
void CtrlEndKey::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Memo *memo = this->otherNoteForm->GetMemo();
	memo->MoveLastRow();

	Line *line = memo->GetLine(memo->GetRow());
	line->MoveLastColumn();

	Caret *caret = Caret::Instance(this->otherNoteForm);
	caret->MoveLastLine();
	caret->MoveLastCharacter();
}