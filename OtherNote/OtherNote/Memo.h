#pragma once
//Memo.h

#ifndef _MEMO_H
#define _MEMO_H

#include "Array.h"
#include "Line.h"

typedef signed long int Long;

class Memo {
public:
	Memo(Long capacity = 100);
	Memo(const Memo& source);
	~Memo();
	void Write(char value);
	void Write(char* value);
	Line& GetAt(Long row);
	Long Erase();

	Long GetCapacity() const;
	Long GetLength() const;
	Long GetRow() const;
	Long GetColumn() const;
	void SetColumn(Long column);
private:
	Array<Line> lines;
	Long capacity;
	Long length;
	Long row;
	Long column;
};

inline Long Memo::GetCapacity() const {
	return this->capacity;
}

inline Long Memo::GetLength() const {
	return this->length;
}
inline Long Memo::GetRow() const {
	return this->row;
}

inline Long Memo::GetColumn() const {
	return this->column;
}

inline void Memo::SetColumn(Long column) {
	this->column = column;
}
#endif	//_MEMO_H