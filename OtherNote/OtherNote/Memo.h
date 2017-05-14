#pragma once
//Memo.h

#ifndef _MEMO_H
#define _MEMO_H

#include "Composite.h"

class Visitor;
class Line;
class Memo :public Composite {
public:
	Memo(Long capacity = 250);
	Memo(const Memo& source);
	virtual ~Memo();
	virtual Contents* Clone();
	Memo& operator=(const Memo& source);
	Long AddLine(Contents *contentsLink);
	Long RemoveLine(Long index);
	Line* GetLine(Long index);
	Line* operator[](Long index);
	Long GetRow() const;
	void Memo::Accept(Visitor* visitor);
public:
	Long row;
};

inline Long Memo::GetRow() const {
	return this->row;
}

#endif	//_MEMO_H