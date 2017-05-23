// SaveVisitor.h

#ifndef _SAVEVISITOR_H
#define _SAVEVISITOR_H

#include "Visitor.h"
#include <fstream>
using namespace std;

class SaveVisitor : public Visitor {
public:
	SaveVisitor();
	SaveVisitor(const SaveVisitor& source);
	~SaveVisitor();
	SaveVisitor& operator=(const SaveVisitor& source);
	virtual void Visit(SingleCharacter *singleCharacter);
	virtual void Visit(DoubleCharacter *doubleCharacter);
	virtual void Visit(Memo *memo);
	virtual void Visit(Line *line);
public:
	fstream fs;
};



#endif //_SAVEVISITOR_H