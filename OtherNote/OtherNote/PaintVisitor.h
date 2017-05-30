#pragma once
//PaintVisitor.h

#ifndef _PAINTVISITOR_H
#define _PAINTVISITOR_H

#include "Visitor.h"

class CDC;
class CRect;
class PaintVisitor :public Visitor {
public:
	PaintVisitor(CDC *dc = 0, CRect *rect = 0);
	PaintVisitor(const PaintVisitor& source);
	virtual ~PaintVisitor();
	PaintVisitor& operator=(const PaintVisitor& source);
	virtual void Visit(Memo *memo);
	virtual void Visit(Line *line);
	virtual void Visit(SingleCharacter *singleCharacter);
	virtual void Visit(DoubleCharacter *doubleCharacter);
	CDC* GetDC() const;
	CRect* GetRect() const;
private:
	CDC *dc;
	CRect *rect;
};

inline CDC* PaintVisitor::GetDC() const {
	return const_cast<CDC*>(this->dc);
}

inline CRect* PaintVisitor::GetRect() const {
	return const_cast<CRect*>(this->rect);
}

#endif	//_PAINTVISITOR_H