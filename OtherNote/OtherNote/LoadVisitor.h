// LoadVisitor.h

#ifndef _LOADVISITOR_H
#define _LOADVISITOR_H

#include "Visitor.h"
#include <fstream>
using namespace std;

class LoadVisitor : public Visitor {
public:
	LoadVisitor();
	LoadVisitor(const LoadVisitor& source);
	~LoadVisitor();
	LoadVisitor& operator=(const LoadVisitor& source);
	void Visit(SingleCharacter *singleCharacter);
	void Visit(DoubleCharacter *doubleCharacter);
	void Visit(Memo *memo);
	void Visit(Line *line);
private:
	fstream fs;
	bool isEof;
	bool isBad;
};


#endif //_LOADVISITOR_H