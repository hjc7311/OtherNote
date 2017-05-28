//Memo.cpp

#include "Memo.h"
#include "Line.h"
#include "Visitor.h"
#include "Iterator.h"
#include "ArrayIterator.h"

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

Contents* Memo::Clone() const {
	return new Memo(*this);
}

Long Memo::AddLine() {
	this->row = Composite::Add(new Line);
	return this->row;
}

Long Memo::InsertLine(Long index) {
	this->row++;
	index = Composite::Insert(index, new Line);
	return index;	
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

void Memo::Accept(Visitor* visitor) {
	//ArrayIterator<Line*> *lineIterator = new ArrayIterator<Line*>(&(this->contents));
	//for (ArrayIterator<Line*> lineIterator(&(this->contents)); !lineIterator.IsDone(); lineIterator.Next()) {
	//	i.CurrentItem()->Accept(visitor);
	//}
	visitor->Visit(this);
}

//ArrayIterator<Contents*>* Memo::CreateIterator() const {
//	return Composite::CreateIterator();
////	return new ArrayIterator<Contents*>(&this->contents);
//}

void Memo::SetRow(Long index) {
	this->row = index;
}

void Memo::MoveUpRow() {
	this->row--;
}

void Memo::MoveDownRow() {
	this->row++;
}