#pragma once
//PaintVisitor.h

#ifndef _PAINTVISITOR_H
#define _PAINTVISITOR_H

#include "Visitor.h"

class CDC;
class PaintVisitor :public Visitor {
public:
	PaintVisitor();
	PaintVisitor(CDC *dc);
	PaintVisitor(const PaintVisitor& source);
	virtual ~PaintVisitor();
	PaintVisitor& operator=(const PaintVisitor& source);
	virtual void Visit(Line *line);
	virtual void Visit(Memo *memo);
	virtual void Visit(SingleCharacter *singleCharacter);
	virtual void Visit(DoubleCharacter *doubleCharacter);
	CDC* GetDC() const;
private:
	CDC *dc;
};

inline CDC* PaintVisitor::GetDC() const {
	return const_cast<CDC*>(this->dc);
}

#endif	//_PAINTVISITOR_H