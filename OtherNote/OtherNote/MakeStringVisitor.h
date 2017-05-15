#pragma once
//MakeStringVisitor.h

#ifndef _MAKESTRINGVISITOR_H
#define _MAKESTRINGVISITOR_H
#include "Visitor.h"
#include <string>
using namespace std;

class Line;
class Memo;
class SingleCharactrer;
class DoubleCharacter;
class MakeStringVisitor :public Visitor{
public:
	MakeStringVisitor();
	virtual ~MakeStringVisitor();
	MakeStringVisitor(const MakeStringVisitor& source);
	MakeStringVisitor& operator=(const MakeStringVisitor& source);
	virtual void Visit(Line *line);
	virtual void Visit(Memo *memo);
	virtual void Visit(SingleCharacter *singleCharacter);
	virtual void Visit(DoubleCharacter *doubleCharaceter);
	string GetStr();

private:
	string str;
};
inline string MakeStringVisitor::GetStr() {
	return this->str;
}
#endif//_MAKESTRINGVISITOR_H