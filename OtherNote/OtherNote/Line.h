#pragma once
//Line.h

#ifndef _LINE_H
#define _LINE_H

#include "Array.h"

typedef signed long int Long;

class Character;

class Line {
public:
	Line(Long capacity = 100);
	~Line();
	Long Write(char value, Long column);
	Long Write(char* value, Long column);
	Character* GetAt(Long index);
	Long Erase(Long index);
	Line(const Line& source);
	Line& operator=(const Line& source);

	Long GetCapacity() const;
	Long GetLength() const;
private:
	Array<Character*> characters;
	Long capacity;
	Long length;
};

inline Long Line::GetCapacity() const {
	return this->capacity;
}

inline Long Line::GetLength() const {
	return this->length;
}

#endif	//_LINE_H