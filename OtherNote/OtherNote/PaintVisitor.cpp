//PaintVisitor.cpp

#include "PaintVisitor.h"
#include "Line.h"
#include "Memo.h"
#include "CharacterFaces.h"
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
	CharacterFaces *instance = CharacterFaces::Instance(this->dc);
	CFont font;
	font.CreatePointFont(instance->GetFontSize(), instance->GetFontFamily().c_str());
	dc->SelectObject(&font);
	/*CFont font;
	font.CreatePointFont(500, "Tahoma");
	dc->SelectObject(&font);*/
	RECT rect = { 0, 0, 1000, 1000 };	
																	
	//Long characterSize[26][3];
	//Long i = 65;
	//CSize csize;
	//string print;
	////string subjectString;
	////char character;
	//while (i <= 90) {
	//	//character = i;
	//	//subjectString = string(1, i);
	//	characterSize[i-65][0] = i;
	//	csize = this->dc->GetTextExtent(static_cast<char>(i));
	//	characterSize[i-65][1] = csize.cx;
	//	characterSize[i-65][2] = csize.cy;
	//	print = print+to_string(characterSize[i - 65][0])+ " "+ to_string(characterSize[i - 65][1]) + " " + to_string(characterSize[i - 65][2])+"\n";
	//	i++;
	//}
	//CharacterFaces *characterFaces = CharacterFaces::Instance(this->dc);
	//subjectString = to_string(&characterFaces[0][0]); 
	//print = print + subjectString + " ";
	//subjectString = string(1, &(characterFaces[0][1]));
	//print = print + subjectString + "\n";
	//this->dc->DrawText(CString(print.c_str()), &rect, DT_EDITCONTROL | DT_WORDBREAK | DT_LEFT | DT_EXPANDTABS);
	
	this->dc->DrawText(CString(makeStringVisitor.GetStr().c_str()), &rect, DT_EDITCONTROL | DT_WORDBREAK | DT_LEFT | DT_EXPANDTABS);


	//this->dc->DrawText(CString(makeStringVisitor.GetStr().c_str()), &rect,  DT_EDITCONTROL|DT_WORDBREAK|DT_LEFT|DT_EXPANDTABS);
	//CFont cfont;
	//VERIFY(cfont.CreateFont(
	//	50,                        // nHeight
	//	0,                        // nWidth
	//	0,                         // nEscapement
	//	0,                         // nOrientation
	//	FW_NORMAL,                 // nWeight
	//	FALSE,                     // bItalic
	//	FALSE,                     // bUnderline
	//	0,                         // cStrikeOut
	//	ANSI_CHARSET,              // nCharSet
	//	OUT_DEFAULT_PRECIS,        // nOutPrecision
	//	CLIP_DEFAULT_PRECIS,       // nClipPrecision
	//	DEFAULT_QUALITY,           // nQuality
	//	DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
	//	_T("Arial")));                 // lpszFacename

	//// Do something with the font just created...

	//CFont* def_font = this->dc->SelectObject(&cfont);
	//this->dc->TextOut(5, 5, _T("Hello"), 5);
	//this->dc->SelectObject(def_font);

	//// Done with the font.  Delete the font object.
	//cfont.DeleteObject();
}
