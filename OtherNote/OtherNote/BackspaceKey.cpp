//BackspaceKey.cpp

#include "BackspaceKey.h"
#include "OtherNoteForm.h"

BackspaceKey::BackspaceKey(OtherNoteForm *otherNoteForm)
	:KeyAction(otherNoteForm) {
}

BackspaceKey::BackspaceKey(const BackspaceKey& source)
	:KeyAction(source) {
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
void BackspaceKey::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Memo *memo = this->otherNoteForm->GetMemo();
	Line *line = memo->GetLine(memo->GetRow());

	Caret *caret = Caret::Instance(this->otherNoteForm);

	if (line->GetLength() != 0) {
		caret->MovePreviousCharacter();
		line->Erase();		
	}
	else if (memo->GetRow() != 0) {
		if (memo->GetLength() > 1) {
			memo->RemoveLine();			
			line->MovePreviousColumn();
			//caret->MovePreviousCharacter();
		}
	}
	//if (line->GetLength() != 0) {
	//	line->Erase();
	//}
	//else if (memo->GetRow() != 0 && line->GetLength() == 0) {
	//	if (memo->GetLength() != 1) {
	//		memo->RemoveLine();
	//		Line *currentLineLink = memo->GetLine(memo->GetLength() - 1);
	//		//currentLineLink->SetColumn(currentLineLink->GetLength());
	//		currentLineLink->MovePreviousColumn();
	//	}
	//}
}