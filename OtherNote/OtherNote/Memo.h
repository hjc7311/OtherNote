#pragma once
//Memo.h

#ifndef _MEMO_H
#define _MEMO_H

#include "Composite.h"
#include "Iterator.h"
#include <string>
using namespace std;

class Visitor;
class Line;
class Memo :public Composite {
public:
	Memo(Long capacity = 250);
	Memo(const Memo& source);
	virtual ~Memo();
	virtual Contents* Clone() const;
	Memo& operator=(const Memo& source);
	Long AddLine();
	Long InsertLine(Long index);
	Long RemoveLine(Long index);
	Line* GetLine(Long index);
	Line* operator[](Long index);
	Long GetRow() const;
	void SetRow(Long index);
	void Accept(Visitor* visitor);
	void MoveUpRow();
	void MoveDownRow();
//	virtual ArrayIterator<Contents*>* CreateIterator() const;
	//string MakeMemoString();
private:
	Long row;
};

inline Long Memo::GetRow() const {
	return this->row;
}

#endif	//_MEMO_H