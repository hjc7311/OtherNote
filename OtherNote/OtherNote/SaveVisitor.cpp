// SaveVisitor.cpp

#include "SaveVisitor.h"
#include "MakeStringVisitor.h"
#include "Line.h"
#include "CharacterFaces.h"
#include "Memo.h"

SaveVisitor::SaveVisitor()
	:fs("aha.txt") {
}

SaveVisitor::SaveVisitor(const SaveVisitor& source)
	:fs("aha.txt", ios::in | ios::out) {
}

SaveVisitor::~SaveVisitor(){
	fs.close();
}

SaveVisitor& SaveVisitor::operator=(const SaveVisitor& source) {
	return *this;
}

void SaveVisitor::Visit(SingleCharacter *singleCharacter) {
}

void SaveVisitor::Visit(DoubleCharacter *doubleCharacter) {
}

void SaveVisitor::Visit(Memo *memo) {
	CharacterFaces *characterFaces = CharacterFaces::Instance(0);
	this->fs<<characterFaces->GetFontFamily().c_str()<<"\r\n"<<characterFaces->GetFontSize()<<"\r\n";

	Long i = 0;
	while (i < memo->GetLength()) {
		Line *line = memo->GetLine(i);
		line->Accept(this);
		this->fs<<"\r\n";
		i++;
	}
}

void SaveVisitor::Visit(Line *line) {
	MakeStringVisitor makeStringVisitor;

	line->Accept(&makeStringVisitor);
	
	this->fs<<makeStringVisitor.GetStr().c_str();
}