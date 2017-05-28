// MakeStringVisitor.h

#ifndef MAKESTRINGSVISITOR_H
#define MAKESTRINGSVISITOR_H

#include "Visitor.h"
#include <string>
using namespace std;

class MakeStringVisitor : public Visitor {
public:
	MakeStringVisitor();
	MakeStringVisitor(const MakeStringVisitor& soure);
	virtual ~MakeStringVisitor();
	MakeStringVisitor& operator=(const MakeStringVisitor& soure);
	virtual void Visit(Memo *memo);
	virtual void Visit(Line *line);
	virtual void Visit(SingleCharacter *singleCharacter);
	virtual void Visit(DoubleCharacter *doubleCharacter);
	string& GetCompleteString() const;
private:
	string completeString;
};

inline string& MakeStringVisitor::GetCompleteString() const{
	return const_cast<string&>(this->completeString);
}

#endif	//_MAKESTRINGVISITOR_H