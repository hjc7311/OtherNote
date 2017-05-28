//Memo.cpp

#include "Memo.h"
#include "Line.h"

Memo::Memo(Long capacity)
	:Composite(capacity)
{
	this->row = Composite::Add(new Line);
}

Memo::Memo(const Memo& source)
	: Composite(source)
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

Long Memo::AddLine() {
	this->row = Composite::Add(new Line);
	return this->row;
}

Long Memo::RemoveLine(Long index) {
	index = Composite::Remove(index);
	this->row--;

	return index;
}

Line* Memo::GetLine(Long index) {
	return static_cast<Line*>(Composite::GetAt(index));
}

Line* Memo::operator[](Long index) {
	return static_cast<Line*>(Composite::GetAt(index));
}

Contents* Memo::Clone() const {
	return new Memo(*this);
}

#include "Visitor.h"
void Memo::Accept(Visitor* visitor) {
	visitor->Visit(this);
}

#include "ArrayIterator.h"
Iterator<Contents*>* Memo::CreateIterator() const {
	return new ArrayIterator<Contents*>(&this->contents);
}

void Memo::MoveUpRow() {
	this->row--;
	//if (this->row < 0) {
	//	this->row++;
	//}
}

void Memo::MoveDownRow() {
	this->row++;
	//if (this->row >= this->length) {
	//	this->row--;
	//}
}