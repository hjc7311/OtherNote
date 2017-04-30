#pragma once
//Memo.h

#ifndef _MEMO_H
#define _MEMO_H

#include "SingleCharacter.h"
#include "Array.h"

typedef signed long int Long;

class Memo {
public:
	Memo(Long capacity = 100);
	~Memo();
	Long Write(char value);
	//Long Write();
	SingleCharacter& GetAt(Long index);
	Long GetCapacity() const;
	Long GetLength() const;
private:
	Array<SingleCharacter> singleCharacters;
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