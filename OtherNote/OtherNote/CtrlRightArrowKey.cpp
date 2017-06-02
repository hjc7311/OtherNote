//CtrlRightArrowKey.cpp

#include "CtrlRightArrowKey.h"
#include "OtherNoteForm.h"

CtrlRightArrowKey::CtrlRightArrowKey(OtherNoteForm *otherNoteForm)
	:KeyAction(otherNoteForm) {

}

CtrlRightArrowKey::CtrlRightArrowKey(const CtrlRightArrowKey& source)
	: KeyAction(source) {

}

CtrlRightArrowKey::~CtrlRightArrowKey() {

}

CtrlRightArrowKey& CtrlRightArrowKey::operator=(const CtrlRightArrowKey& source) {
	KeyAction::operator=(source);

	return *this;
}

#include "Caret.h"
#include "Memo.h"
#include "Line.h"
#include "Character.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
void CtrlRightArrowKey::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Memo *memo = this->otherNoteForm->GetMemo();
	Line *line = memo->GetLine(memo->GetRow());

	Caret *caret = Caret::Instance(this->otherNoteForm);

	if (memo->GetRow() < memo->GetLength() - 1 || line->GetColumn() < line->GetLength()) {
		if (line->GetColumn() < line->GetLength()) {
			char previousCharacter = '\0';
			line->MoveNextColumn();
			caret->MoveNextCharacter();
			Character *character = line->GetCharacter(line->GetColumn());
			char currentCharacter = '\0';
			if (dynamic_cast<SingleCharacter*>(character)) {
				currentCharacter = dynamic_cast<SingleCharacter*>(character)->GetValue();
			}
			else if (dynamic_cast<DoubleCharacter*>(character)) {
				currentCharacter = 'a';
			}

			//while (currentCharacter < 33 || currentCharacter > 126 || previousCharacter != ' ') {
			while ((currentCharacter < 33 || currentCharacter > 126 || previousCharacter != ' ') && line->GetColumn() < line->GetLength() - 1) {
				line->MoveNextColumn();
				caret->MoveNextCharacter();
				character = line->GetCharacter(line->GetColumn());
				previousCharacter = currentCharacter;
				if (dynamic_cast<SingleCharacter*>(character)) {
					currentCharacter = dynamic_cast<SingleCharacter*>(character)->GetValue();
				}
				else if (dynamic_cast<DoubleCharacter*>(character)) {
					currentCharacter = 'a';
				}
			}
			if (line->GetColumn() == line->GetLength() - 1) {
				line->MoveNextColumn();
				caret->MoveNextCharacter();
			}
		}
		else if (line->GetColumn() == line->GetLength()) {
			memo->MoveNextRow();
			line = memo->GetLine(memo->GetRow());
			line->MoveFirstColumn();
			caret->MoveNextLine();
		}
	}
}