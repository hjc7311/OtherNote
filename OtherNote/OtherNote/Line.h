#pragma once
//Line.h

#ifndef _LINE_H
#define _LINE_H

#define KOREAN 127

#include "Composite.h"

class Character;
class Visitor;
class Line : public Composite {
public:
	Line(Long capacity = 256);
	Line(const Line& source);
	virtual ~Line();
	Line& operator=(const Line& source);
	Long Write(char value);
	Long Write(char *value);
	Long Erase();
	Character* GetCharacter(Long index);
	Character* operator[](Long index);
	Long GetColumn() const;
	virtual Contents* Clone() const;
	virtual void Accept(Visitor* visitor);
	virtual Iterator<Contents*>* CreateIterator() const;
	Long MoveLeftColumn();
	Long MoveRightColumn();
private:
	Long column;
};

inline Long Line::GetColumn() const {
	return this->column;
}

#endif	//_LINE_H