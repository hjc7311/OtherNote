#pragma once
//Line.h

#ifndef _LINE_H
#define _LINE_H

#include "Composite.h"

#include <string>
using namespace std;

class Visitor;
class Character;
class Line : public Composite {
public:
	Line(Long capacity = 256);
	Line(const Line& source);
	virtual ~Line();
	virtual Contents* Clone();
	Line& operator=(const Line& source);
	Long Write(char value);
	Long Write(char *value);
	Long Erase();
	Character* GetCharacter(Long index);
	Character* operator[](Long index);
	Long GetColumn() const;
	string GetLineString();
	void Accept(Visitor* visitor);
public:
	Long column;
};

inline Long Line::GetColumn() const {
	return this->column;
}

#endif	//_LINE_H