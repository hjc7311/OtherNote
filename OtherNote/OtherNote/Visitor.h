#pragma once
//Visitor.h

#ifndef _VISITOR_H
#define _VISITOR_H

class Memo;
class Line;
class SingleCharacter;
class DoubleCharacter;
class Visitor {
public:
	Visitor();
	virtual ~Visitor() = 0;
	Visitor(const Visitor& source);
	Visitor& operator=(const Visitor& source);
	virtual void Visit(Memo *memo) = 0;
	virtual void Visit(Line *line) = 0;
	virtual void Visit(SingleCharacter *singleCharacter) = 0;
	virtual void Visit(DoubleCharacter *doubleCharaceter) = 0;
};

#endif	//_VISITOR_H