//Memo.cpp

#include "Memo.h"
#include "Line.h"
#include "Visitor.h"

Memo::Memo(Long capacity)
	:Composite(capacity)
{
	this->row = Composite::Add(new Line);
}

Memo::Memo(const Memo& source)
	:Composite(source)
{
	this->row = source.row;
}

Memo::~Memo() {
	//Composite::~Composite();
}

Memo& Memo::operator=(const Memo& source) {
	Composite::operator=(source);
	this->row = source.row;
	return *this;
}

Contents* Memo::Clone() {
	return new Memo(*this);
}

Long Memo::AddLine() {
	this->row = Composite::Add(new Line);
	return this->row;
}

Long Memo::RemoveLine(Long index) {
	index= Composite::Remove(index);
	this->row--;
	return index;
}

Line* Memo::GetLine(Long index) {
	return static_cast<Line*>(Composite::GetAt(index));
}

Line* Memo::operator[](Long index) {
	return static_cast<Line*>(Composite::GetAt(index));
}

void Memo::Accept(Visitor* visitor) {
	visitor->Visit(this);
}