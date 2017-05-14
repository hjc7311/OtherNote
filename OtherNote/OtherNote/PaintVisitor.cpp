//PaintVisitor.cpp

#include "PaintVisitor.h"
#include "Line.h"
#include <afxWin.h>

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

void PaintVisitor::Visit(SingleCharacter *singleCharacter) {

}

void PaintVisitor::Visit(DoubleCharacter *doubleCharacter) {

}

void PaintVisitor::Visit(Line *line) {
	CString lineString(line->GetLineString().c_str());

	RECT rect {0, 0, 1000, 1000};
	//GetClientRect(&rect);
	
	CFont font;
	font.CreatePointFont(200, "Tahoma");
	dc->SelectObject(&font);

	//this->dc->TextOut(0,0,lineString);

	this->dc->DrawText(lineString, &rect, DT_EDITCONTROL | DT_WORDBREAK | DT_LEFT | DT_EXPANDTABS);
}
#include "Memo.h"

void PaintVisitor::Visit(Memo *memo) {
	Long i = 0;
	while (i < memo->GetLength()) {
		memo->GetLine(i)->Accept(this);
		i++;
	}
}
