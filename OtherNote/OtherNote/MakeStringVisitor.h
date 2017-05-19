// MakeStringVisitor.h

#ifndef MAKESTRINGVISITOR_H
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
	virtual void Visit(SingleCharacter *singleCharacter);
	virtual void Visit(DoubleCharacter *doubleCharacter);
	virtual void Visit(Line *line);
	virtual void Visit(Memo *memo);
	string& GetStr() const;
private:
	string str;
};

inline string& MakeStringVisitor::GetStr() const{
	return const_cast<string&>(this->str);
}

#endif	//MakeStringVisitor.h