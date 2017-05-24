// LoadVisitor.cpp

#include "LoadVisitor.h"
#include "CharacterFaces.h"
#include "Line.h"
#include "Memo.h"
#include <afxwin.h>
#include <string>
#include <stdlib.h>
using namespace std;

typedef signed long int Long;

LoadVisitor::LoadVisitor()
	:fs("OtherNote.txt", ios::in) {
	//this->isEof = false;
	//this->isBad = false;
	//if(!(this->fs.bad())){
	//	this->isBad = true;
	//}
}

LoadVisitor::LoadVisitor(const LoadVisitor& source)
	:fs("OtherNote.txt", ios::in) {
}

LoadVisitor::~LoadVisitor() {
	this->fs.close();
}

LoadVisitor& LoadVisitor::operator=(const LoadVisitor& source) {
	return *this;
}

void LoadVisitor::Visit(SingleCharacter *singleCharacter) {
}

void LoadVisitor::Visit(DoubleCharacter *doubleCharacter) {
}

void LoadVisitor::Visit(Memo *memo) {
	char buffer[256];

	if (!this->fs.fail()) {

		this->fs.getline(buffer, sizeof(buffer));

		CharacterFaces *characterFaces = CharacterFaces::Instance(0);
		characterFaces->SetFontFamily(static_cast<string>(buffer));

		this->fs.getline(buffer, sizeof(buffer));
		
		Long fontSize = atoi(buffer);
		characterFaces->SetFontSize(fontSize);
		
		Long j;
		Long i = 0;
//		this->fs.getline(buffer, sizeof(buffer));
		while (!this->fs.eof()) {
			Line *line = memo->GetLine(i);
			line->Accept(this);
			j = memo->AddLine();
			i++;
		}
		memo->RemoveLine(j);
	}
}

void LoadVisitor::Visit(Line *line) {

	char buffer[256];

	this->fs.getline(buffer, sizeof(buffer));

//	if(!this->fs.eof()) {
		Long length = CString(buffer).GetLength();
	
		char doubleCharacter[2];

		Long i = 0;
		while(i < length-1) {
			if(buffer[i] >= 0 && buffer[i] < 130){
				line->Write(buffer[i]);
			}
			else {
				doubleCharacter[0] = buffer[i];
				doubleCharacter[1] = buffer[i+1];
				i++;
				line->Write(doubleCharacter);
			}
			i++;
		}

//		this->fs.getline(buffer, sizeof(buffer));

//	}
	//else {
	//	this->isEof = true;
	//}
}