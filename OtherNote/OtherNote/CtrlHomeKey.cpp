//CtrlHomeKey.cpp

#include "CtrlHomeKey.h"
#include "OtherNoteForm.h"

CtrlHomeKey::CtrlHomeKey(OtherNoteForm *otherNoteForm)
	:KeyAction(otherNoteForm) {

}

CtrlHomeKey::CtrlHomeKey(const CtrlHomeKey& source)
	: KeyAction(source) {

}

CtrlHomeKey::~CtrlHomeKey() {

}

CtrlHomeKey& CtrlHomeKey::operator=(const CtrlHomeKey& source) {
	KeyAction::operator=(source);

	return *this;
}

#include "Caret.h"
#include "Memo.h"
#include "Line.h"
void CtrlHomeKey::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Memo *memo = this->otherNoteForm->GetMemo();
	memo->MoveFirstRow();

	Line *line = memo->GetLine(memo->GetRow());
	line->MoveFirstColumn();

	Caret *caret = Caret::Instance(this->otherNoteForm);
	caret->MoveFirstLine();
}