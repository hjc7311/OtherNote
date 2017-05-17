//Line.cpp

#include "Line.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
#include "Visitor.h"

Line::Line(Long capacity)
	:Composite(capacity) {
	this->column = 0;
}

Line::Line(const Line& source)
	:Composite(source) {
	this->column = source.column;
}

Line& Line::operator=(const Line& source) 
{	
	Composite::operator=(source);
	this->column = source.column;
	return *this;
}

Line::~Line() {
	//Composite::~Composite();
}

Contents* Line::Clone() {
	return new Line(*this);
}

Long Line::Write(char value) {
	Long index = Composite::Add(new SingleCharacter(value));
	this->column++;
	return index;
}

Long Line::Write(char* value) {
	Long index = Composite::Add(new DoubleCharacter(value));
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

string Line::GetLineString() {
	string lineString;

	Character *characterLink;
	Long i = 0;
	while (i < this->length) {
		
		characterLink = this->GetCharacter(i);
		if (dynamic_cast<SingleCharacter*>(characterLink)) {
			lineString += (dynamic_cast<SingleCharacter*>(characterLink))->GetValue();
		}
		else if (dynamic_cast<DoubleCharacter*>(characterLink)) {
			lineString += (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue()[0];
			lineString += (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue()[1];
		}
		i++;
	}
	return lineString;
}

void Line::Accept(Visitor* visitor) {
	visitor->Visit(this);
}