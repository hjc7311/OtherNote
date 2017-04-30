#pragma once
//Memo.h

#ifndef _MEMO_H
#define _MEMO_H

#include "Array.h"
#include <string>
using namespace std;

typedef signed long int Long;

class Character;

class Memo {
public:
	Memo(Long capacity = 100);
	~Memo();
	Long Write(char value);
	Long Write(string value);
	Character* GetAt(Long index);
	Long GetCapacity() const;
	Long GetLength() const;
private:
	Array<Character*> characters;
	Long capacity;
	Long length;
};

inline Long Memo::GetCapacity() const {
	return this->capacity;
}

inline Long Memo::GetLength() const {
	return this->length;
}

#endif	//_MEMO_H