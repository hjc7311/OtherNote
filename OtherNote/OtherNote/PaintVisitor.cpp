//PaintVisitor.cpp

#include "PaintVisitor.h"
#include "Memo.h"
#include "Line.h"
#include "CharacterFaces.h"
#include <afxWin.h>
using namespace std;

//PaintVisitor::PaintVisitor()
//	:Visitor() {
//
//}

//PaintVisitor::PaintVisitor(CDC *dc)
//	: Visitor(), dc(dc) {
//
//}

PaintVisitor::PaintVisitor(CDC *dc, CRect* rect)
	:Visitor() {
	this->dc = dc;
	this->rect = rect;
}

PaintVisitor::PaintVisitor(const PaintVisitor& source)
	: Visitor(source) {
	this->dc = source.dc;
	this->rect = source.rect;
}

PaintVisitor::~PaintVisitor() {

}

PaintVisitor& PaintVisitor::operator=(const PaintVisitor& source) {
	Visitor::operator=(source);
	this->dc = source.dc;
	this->rect = source.rect;

	return *this;
}

#include "MakeStringVisitor.h"
void PaintVisitor::Visit(Memo *memo) {
	MakeStringVisitor makeStringVisitor;
	memo->Accept(&makeStringVisitor);

	CharacterFaces *characterFaces = CharacterFaces::Instance(this->dc);
	CFont font;
	font.CreatePointFont(characterFaces->GetFontSize(), characterFaces->GetFontFamily().c_str());
	this->dc->SelectObject(&font);

//	this->dc->TabbedTextOut(0, 0, makeStringVisitor.GetCompleteString().c_str(), 8, 0, 0);
//	this->dc->TextOut(0,0, makeStringVisitor.GetCompleteString().c_str());
	this->dc->DrawText(CString(makeStringVisitor.GetCompleteString().c_str()), this->rect, DT_EDITCONTROL | DT_WORDBREAK | DT_LEFT | DT_EXPANDTABS);
}

void PaintVisitor::Visit(Line *line) {

}

void PaintVisitor::Visit(SingleCharacter *singleCharacter) {

}

void PaintVisitor::Visit(DoubleCharacter *doubleCharacter) {

}