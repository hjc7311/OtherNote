//BackspaceKey.cpp

#include "BackspaceKey.h"
#include "OtherNoteForm.h"

BackspaceKey::BackspaceKey(OtherNoteForm *otherNoteForm)
	:KeyAction(otherNoteForm) {
}

BackspaceKey::BackspaceKey(const BackspaceKey& source)
	: KeyAction(source) {
}

BackspaceKey::~BackspaceKey() {

}

BackspaceKey& BackspaceKey::operator=(const BackspaceKey& source) {
	KeyAction::operator=(source);
	return *this;
}

#include "Memo.h"
#include "Line.h"
#include "Caret.h"
#include "Character.h"
#include "HorizontalScroll.h"

void BackspaceKey::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Memo *memo = this->otherNoteForm->GetMemo();
	Line *line = memo->GetLine(memo->GetRow());

	Caret *caret = Caret::Instance(this->otherNoteForm);
	
	if (line->GetLength() != 0 && line->GetColumn() != 0) {
		caret->MovePreviousCharacter();
		line->Erase();
	}
	else if (memo->GetRow() != 0) {
		if (line->GetLength() == 0) {
			caret->MovePreviousLine();
			memo->RemoveLine();
			memo->GetLine(memo->GetRow())->MoveLastColumn();
			caret->MoveLastCharacter();
		}
		else {
			Line *lineToCopy = memo->GetLine(memo->MovePreviousRow());

			caret->MovePreviousLine();
			lineToCopy->MoveLastColumn();
			caret->MoveLastCharacter();

			Long i = 0;
			while (i < line->GetLength()) {
				Contents *contents = line->GetCharacter(i)->Clone();
				lineToCopy->Add(contents);
				i++;
			}
			memo->MoveNextRow();
			memo->RemoveLine();
		}
	}
	this->otherNoteForm->GetHorizontalScroll()->UpdateLine();
	this->otherNoteForm->RedrawWindow();
}