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
	//font.CreateFont(
	//	130,                        // nHeight
 //     0,                         // ntWidth
 //     0,                         // nEscapement
 //     0,                         // nOrientation
 //     FW_NORMAL,                 // nWeight
 //     TRUE,                     // bItalic
 //     TRUE,                     // bUnderline
 //     0,                         // cStrikeOut
 //     ANSI_CHARSET,              // nCharSet
 //     OUT_DEFAULT_PRECIS,        // nOutPrecision
 //     CLIP_DEFAULT_PRECIS,       // nClipPrecision
 //     DEFAULT_QUALITY,           // nQuality
 //     DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
 //     _T("consolas")
	//	);
	font.CreatePointFont(200, "Tahoma");
	dc->SelectObject(&font);
	this->dc->DrawText(CString(makeStringVisitor.GetStr().c_str()), &rect,  DT_EDITCONTROL|DT_WORDBREAK|DT_LEFT|DT_EXPANDTABS);
}
