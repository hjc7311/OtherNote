//DeleteKey.cpp

#include "DeleteKey.h"
#include "OtherNoteForm.h"

DeleteKey::DeleteKey(OtherNoteForm *otherNoteForm) 
	:KeyAction(otherNoteForm){
}

DeleteKey::DeleteKey(const DeleteKey& source) 
	:KeyAction(source){
}

DeleteKey::~DeleteKey() {

}

DeleteKey& DeleteKey::operator=(const DeleteKey& source) {
	KeyAction::operator=(source);
	return *this;
}

#include "Memo.h"
#include "Line.h"
#include "Caret.h"
#include "Character.h"

void DeleteKey::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Memo *memo = this->otherNoteForm->GetMemo();
	Line *line = memo->GetLine(memo->GetRow());

	Caret *caret = Caret::Instance(this->otherNoteForm);

	if (line->GetLength() > 0 && line->GetColumn() < line->GetLength()) {
		line->MoveNextColumn();
		line->Erase();
	}
	else if (memo->GetRow() + 1 < memo->GetLength()){
		if (line->GetLength() == 0) {
			memo->RemoveLine();
			memo->MoveNextRow();
			line = memo->GetLine(memo->GetRow());
			line->MoveFirstColumn();
		}
		else {
			Line *lineToCopy = memo->GetLine(memo->GetRow() + 1);
			//Iterator·Î º¯°æ
			Long i = 0;
			while (i < lineToCopy->GetLength()) {
				Contents *contents = lineToCopy->GetCharacter(i)->Clone();
				line->Add(contents);
				i++;
			}
			memo->MoveNextRow();
			memo->RemoveLine();
		}
	}
	this->otherNoteForm->RedrawWindow();
}