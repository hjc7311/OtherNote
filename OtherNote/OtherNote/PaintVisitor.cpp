//PaintVisitor.cpp

#include "PaintVisitor.h"
#include "Line.h"
#include "Memo.h"
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
	//CString lineString(line->GetLineString().c_str());

	//RECT rect = {0, 0, 1000, 1000};
	////GetClientRect(&rect);
	//
	//CFont font;
	//font.CreatePointFont(200, "Tahoma");
	//dc->SelectObject(&font);

	////this->dc->TextOut(0,0,lineString);

	//this->dc->DrawText(lineString, &rect, DT_EDITCONTROL | DT_WORDBREAK | DT_LEFT | DT_EXPANDTABS);
}

#include "MakeStringVisitor.h"
void PaintVisitor::Visit(Memo *memo) {
	MakeStringVisitor makeStringVisitor;
	memo->Accept(&makeStringVisitor);
	
	RECT rect = {0, 0, 500, 500};
	CFont font;
	font.CreatePointFont(200, "Tahoma");
	dc->SelectObject(&font);
	//this->dc->DrawText(CString(makeStringVisitor.GetStr().c_str()), &rect,  DT_EDITCONTROL|DT_WORDBREAK|DT_LEFT|DT_EXPANDTABS);
	this->dc->DrawText(CString(makeStringVisitor.GetStr().c_str()), &rect,  DT_EDITCONTROL|DT_WORDBREAK|DT_LEFT|DT_EXPANDTABS);
}
