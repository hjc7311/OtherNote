#pragma once
//Memo.h

#ifndef _MEMO_H
#define _MEMO_H

#include "Composite.h"

class Line;
class Memo :public Composite {
public:
	Memo(Long capacity = 250);
	Memo(const Memo& source);
	virtual ~Memo();
	Memo& operator=(const Memo& source);
	Long AddLine();
	Long InsertLine();
	Long RemoveLine();
	Line* GetLine(Long index);
	Line* operator[](Long index);
	Long GetRow() const;
	virtual Contents* Clone() const;
	void Accept(Visitor* visitor);
	virtual ArrayIterator<Contents*>* CreateIterator() const;
	Long MoveFirstRow();
	Long MovePreviousRow();
	Long MoveNextRow();
	Long MoveLastRow();
	//void SetRow(Long index);
private:
	Long row;
};

inline Long Memo::GetRow() const {
	return this->row;
}

#endif	//_MEMO_H