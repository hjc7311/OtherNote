//Mouse.cpp

#include "Mouse.h"
#include "OtherNoteForm.h"

Mouse* Mouse::instance = 0;

Mouse::Mouse(OtherNoteForm *otherNoteForm) {
	this->otherNoteForm = otherNoteForm;
}

Mouse::Mouse(const Mouse& source) {
	this->otherNoteForm = source.otherNoteForm;
}

Mouse::~Mouse() {

}

Mouse& Mouse::operator=(const Mouse& source) {
	this->otherNoteForm = source.otherNoteForm;
	return *this;
}

//Mouse* Mouse::Instance(OtherNoteForm *otherNoteForm, Long xPosition, Long yPosition) {
//	if (instance == 0) {
//		instance = new Mouse;
//	}
//	return instance;
//}

void Mouse::OnMouseMove(UINT nFlags, CPoint point) {
	CWnd::OnMouseMove(nFlags, point);
}

#include "Memo.h"
#include "Line.h"
#include "Character.h"
#include "Caret.h"
void Mouse::OnLButtonDown(UINT nFlags, CPoint point) {
	Caret *caret = Caret::Instance(this->otherNoteForm);
	
	Memo *memo = this->otherNoteForm->GetMemo();
	memo->MoveFirstRow();
	Long height = 0;
	while (height < (point.y - caret->GetHeight()) && memo->GetRow() < memo->GetLength() - 1) {
		memo->MoveNextRow();
		height += caret->GetHeight();
	}
	
	Line *line = memo->GetLine(memo->GetRow());
	line->MoveFirstColumn();
	Long previousWidth = 0;
	Long currentWidth = 0;
	while (currentWidth < point.x && line->GetColumn() < line->GetLength()) {
		previousWidth = currentWidth;
		currentWidth += line->GetCharacter(line->GetColumn())->GetWidth();
		line->MoveNextColumn();
	}

	if (currentWidth - point.x < point.x - previousWidth) {
		caret->Move(currentWidth, height);
	}
	else {
		line->MovePreviousColumn();
		caret->Move(previousWidth, height);
	}
}