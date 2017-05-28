//Line.cpp

#include "Line.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"

Line::Line(Long capacity)
	:Composite(capacity) {
	this->column = 0;
}

Line::Line(const Line& source)
	:Composite(source) {
	this->column = source.column;
}

Line::~Line() {
	//Composite::~Composite();
}

Line& Line::operator=(const Line& source)
{
	Composite::operator=(source);
	this->column = source.column;
	return *this;
}

#include "CharacterFaces.h"
#include "CharacterSize.h"
Long Line::Write(char value) {
	CharacterFaces *_instance = CharacterFaces::Instance(0);
	CharacterSize characterSize(_instance->GetCharacterSize(static_cast<Long>(value)));

	Long index = Composite::Add(new SingleCharacter(value, characterSize.GetWidth(), characterSize.GetHeight()));
	this->column++;
	
	return index;
}

Long Line::Write(char* value) {
	CharacterFaces *_instance = CharacterFaces::Instance(0);
	CharacterSize characterSize(_instance->GetCharacterSize(KOREAN));
	
	Long index = Composite::Add(new DoubleCharacter(value, characterSize.GetWidth(), characterSize.GetHeight()));
	this->column++;
	
	return index;
}

Long Line::Erase() {
	Long index = Composite::Remove(--this->column);
	
	return index;
}

Character* Line::GetCharacter(Long index) {
	return static_cast<Character*>(Composite::GetAt(index));
}

Character* Line::operator[](Long index) {
	return static_cast<Character*>(Composite::GetAt(index));
}


Contents* Line::Clone() const {
	return new Line(*this);
}

#include "Visitor.h"
void Line::Accept(Visitor *visitor) {
	visitor->Visit(this);
}

#include "ArrayIterator.h"
Iterator<Contents*>* Line::CreateIterator() const {
	return new ArrayIterator<Contents*>(&this->contents);
//	return const_cast<ArrayIterator<Contents*>*>(new ArrayIterator<Contents*>(&this->contents));
}

Long Line::MoveLeftColumn() {
	return --this->column;
}

Long Line::MoveRightColumn() {
	return ++this->column;
}