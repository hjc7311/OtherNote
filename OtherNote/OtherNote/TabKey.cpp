//TabKey.cpp

#include "TabKey.h"
#include "OtherNoteForm.h"

TabKey::TabKey(OtherNoteForm *otherNoteForm)
	:KeyAction(otherNoteForm) {

}

TabKey::TabKey(const TabKey& source)
	: KeyAction(source) {

}

TabKey::~TabKey() {

}

TabKey& TabKey::operator=(const TabKey& source) {
	KeyAction::operator=(source);

	return *this;
}

#include "Caret.h"
#include "Memo.h"
#include "Line.h"
#include "Character.h"
void TabKey::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Memo *memo = this->otherNoteForm->GetMemo();
	Line *line = memo->GetLine(memo->GetRow());

	Caret *caret = Caret::Instance(this->otherNoteForm);

}