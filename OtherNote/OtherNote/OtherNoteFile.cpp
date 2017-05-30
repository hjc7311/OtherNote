// OtherNoteFile.cpp

#include "OtherNoteFile.h."
#include "MakeStringVisitor.h"
#include "Line.h"
#include <afxwin.h>

OtherNoteFile::OtherNoteFile() {
	this->fs = 0;
}

OtherNoteFile::OtherNoteFile(const OtherNoteFile& source) {
}

OtherNoteFile::~OtherNoteFile() {
}

OtherNoteFile& OtherNoteFile::operator=(const OtherNoteFile& source) {
	return *this;
}

void OtherNoteFile::LoadModeOpen(char (*fileName)) {
	this->fs = new fstream(fileName, ios::in);
}

void OtherNoteFile::SaveModeOpen(char (*fileName)) {
	this->fs = new fstream(fileName, ios::out | ios::trunc);
}

void OtherNoteFile::Close() {
	this->fs->close();
}

Line* OtherNoteFile::GetLine() {
	char buffer[1024];
	Line *line = 0;
	this->fs->getline(buffer, sizeof(buffer));
	if(!(this->fs->eof())) {
		char doubleCharacter[2];
		line = new Line;
		Long length = CString(buffer).GetLength();
		Long i = 0;
		while(i < length-1) {
			if(buffer[i] >= 0 && buffer[i] <= 127){
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
	return line;
}

void OtherNoteFile::Write(SingleCharacter *singleCharacter) {
	this->fs->put(singleCharacter->GetValue());
}

void OtherNoteFile::Write(DoubleCharacter *doubleCharacter) {
	this->fs->put(doubleCharacter->GetValue()[0]);
	this->fs->put(doubleCharacter->GetValue()[1]);
}

void OtherNoteFile::Write(Line *line) {
	Long length = line->GetLength();
	Long i = 0;
	while(i < length) {
		if(dynamic_cast<SingleCharacter*>(line->GetCharacter(i))) {
			this->fs->put((dynamic_cast<SingleCharacter*>(line->GetCharacter(i)))->GetValue());
		}
		if(dynamic_cast<DoubleCharacter*>(line->GetCharacter(i))) {
			this->fs->put((dynamic_cast<DoubleCharacter*>(line->GetCharacter(i)))->GetValue()[0]);
			this->fs->put((dynamic_cast<DoubleCharacter*>(line->GetCharacter(i)))->GetValue()[1]);
			i++;
		}
		i++;
	}
}

void OtherNoteFile::Write(char character) {
	this->fs->put(character);
}

void OtherNoteFile::Write(string str) {
	this->fs->write(str.c_str(), str.length());
}

void OtherNoteFile::operator<<(SingleCharacter *singleCharacter) {
	this->fs->put(singleCharacter->GetValue());
}

void OtherNoteFile::operator<<(DoubleCharacter *doubleCharacter) {
	this->fs->put(doubleCharacter->GetValue()[0]);
	this->fs->put(doubleCharacter->GetValue()[1]);
}

void OtherNoteFile::operator<<(Line *line) {
	Long length = line->GetLength();
	Long i = 0;
	while(i < length) {
		if(dynamic_cast<SingleCharacter*>(line->GetCharacter(i))) {
			this->fs->put((dynamic_cast<SingleCharacter*>(line->GetCharacter(i)))->GetValue());
		}
		if(dynamic_cast<DoubleCharacter*>(line->GetCharacter(i))) {
			this->fs->put((dynamic_cast<DoubleCharacter*>(line->GetCharacter(i)))->GetValue()[0]);
			this->fs->put((dynamic_cast<DoubleCharacter*>(line->GetCharacter(i)))->GetValue()[1]);
			i++;
		}
		i++;
	}
}

void OtherNoteFile::operator<<(char character) {
	this->fs->put(character);
}

void OtherNoteFile::operator<<(string str) {
	this->fs->write(str.c_str(), str.length());
}

bool OtherNoteFile::IsEOF() {
	return this->fs->eof();
}

bool OtherNoteFile::IsFail() {
	return this->fs->fail();
}