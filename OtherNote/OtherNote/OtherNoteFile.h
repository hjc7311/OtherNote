// OtherNoteFile.h

#ifndef _OTHERNOTEFILE_H
#define _OTHERNOTEFILE_H

#include "Line.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
#include <fstream>
using namespace std;

class OtherNoteFile {
public:
	OtherNoteFile();
	OtherNoteFile(const OtherNoteFile& source);
	~OtherNoteFile();
	OtherNoteFile& operator=(const OtherNoteFile& source);
	void LoadModeOpen(char (*fileName));
	void SaveModeOpen(char (*fileName));
	void Close();
	Line* GetLine();
	void Write(SingleCharacter *singleCharacter);
	void Write(DoubleCharacter *doubleCharacter);
	void Write(Line *line);
	void Write(char character);
	void Write(string str);
	void Write(Long integer);
	void operator<<(SingleCharacter *singleCharacter);
	void operator<<(DoubleCharacter *doubleCharacter);
	void operator<<(Line *line);
	void operator<<(char character);
	void operator<<(string str);
	void operator<<(Long integer);
	bool IsEOF();
	bool IsFail();
private:
	fstream *fs;
};



#endif //_OTHERNOTEFILE_H