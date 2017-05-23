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
	:fs("aha.txt", ios::in | ios::out) {
	this->isEof = false;
	this->isBad = false;
	if(!(this->fs.bad())){
		this->isBad = true;
	}
}

LoadVisitor::LoadVisitor(const LoadVisitor& source)
	:fs("aha.txt") {
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
	if(this->isBad == true){
		this->fs.getline(buffer, sizeof(buffer));
		//Long length = CString(buffer).GetLength();
		CharacterFaces *characterFaces = CharacterFaces::Instance(0);
		characterFaces->SetFontFamily(string(buffer));
		this->fs.getline(buffer, sizeof(buffer));
		CString str(buffer);
		//str.Format("%d", buffer);
		//this->fontSize = (LPCTSTR)str;
		int fontSize = atoi(str);
		characterFaces->SetFontSize(fontSize);
		Long j;
		Long i = 0;
		while(this->isEof == false) {
		Line *line = memo->GetLine(i);
		line->Accept(this);
		j = memo->AddLine();
		i++;
		}
		memo->RemoveLine(j);
	}
}

void LoadVisitor::Visit(Line *line) {
	//char buffer[256];
	//this->fs.getline(buffer, sizeof(buffer));
	////Long length = CString(buffer).GetLength();
	//CharacterFaces *characterFaces = CharacterFaces::Instance(0);
	//characterFaces->SetFontFamily(string(buffer));
	//this->fs.getline(buffer, sizeof(buffer));
	//CString str;
	//str.Format("%d", buffer);
	////this->fontSize = (LPCTSTR)str;
	//int fontSize = atoi(str);
	//characterFaces->SetFontSize(fontSize);
	char buffer[256];
	this->fs.getline(buffer, sizeof(buffer));
	if(!fs.eof()) {
		Long length = CString(buffer).GetLength();
		char doubleCharacter[2];
		Long i = 0;
		while(i < length) {
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
	}
	else {
		this->isEof = true;
	}
}