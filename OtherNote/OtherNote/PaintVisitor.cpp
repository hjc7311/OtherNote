//PaintVisitor.cpp

#include "PaintVisitor.h"
#include "MakeStringVisitor.h"
#include "Memo.h"
#include "Line.h"
#include <afxwin.h>

PaintVisitor::PaintVisitor()
	:Visitor() {

}

PaintVisitor::PaintVisitor(CDC *dc) 
	:Visitor() {
	this->dc = dc;
}

PaintVisitor::PaintVisitor(const PaintVisitor& source)
	: Visitor(source) {
	this->dc = source.dc;
}

PaintVisitor::~PaintVisitor() {

}

PaintVisitor& PaintVisitor::operator=(const PaintVisitor& source) {
	Visitor::operator=(source);
	this->dc = source.dc;
	
	return *this;
}

#include "CharacterFaces.h"
void PaintVisitor::Visit(Memo *memo) {
	MakeStringVisitor makeStringVisitor;
	memo->Accept(&makeStringVisitor);

	CharacterFaces *characterFaces = CharacterFaces::Instance(this->dc);
	CFont font;
	font.CreatePointFont(characterFaces->GetSize(), characterFaces->GetFontFamily().c_str());
	dc->SelectObject(&font);

	CRect rect = {0, 0, 1000, 1000};
	this->dc->DrawText(CString(makeStringVisitor.GetCompleteString().c_str()), &rect,  DT_EDITCONTROL|DT_WORDBREAK|DT_LEFT|DT_EXPANDTABS);
}

void PaintVisitor::Visit(Line *line) {

}

void PaintVisitor::Visit(SingleCharacter *singleCharacter) {

}

void PaintVisitor::Visit(DoubleCharacter *doubleCharacter) {

}