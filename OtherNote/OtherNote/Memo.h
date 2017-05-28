#pragma once
//Memo.h

#ifndef _MEMO_H
#define _MEMO_H

#include "Composite.h"
//#include "Iterator.h"
//#include <string>
//using namespace std;

class Line;
class Visitor;
class Memo : public Composite {
public:
	Memo(Long capacity = 250);
	Memo(const Memo& source);
	virtual ~Memo();
	Memo& operator=(const Memo& source);
	Long AddLine();
	Long RemoveLine(Long index);
	Line* GetLine(Long index);
	Line* operator[](Long index);
	Long GetRow() const;
	virtual Contents* Clone() const;
	virtual void Accept(Visitor* visitor);
	virtual Iterator<Contents*>* CreateIterator() const;
	void MoveUpRow();
	void MoveDownRow();
private:
	Long row;
};

inline Long Memo::GetRow() const {
	return this->row;
}

#endif	//_MEMO_H