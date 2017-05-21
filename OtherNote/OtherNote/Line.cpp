//Line.cpp

#include "Line.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
#include "Visitor.h"
#include "ArrayIterator.h"
#include "CharacterFaces.h"

#define KOREAN 127

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

Contents* Line::Clone() const{
	return new Line(*this);
}

Long Line::Write(char value) {
	CharacterFaces *instance = CharacterFaces::Instance();
	CharacterSize characterSize = instance->GetCharacterSize(static_cast<Long>(value));
	Long index = Composite::Add(new SingleCharacter(value, characterSize.GetWidth(), characterSize.GetHeight()));
	this->column++;
	return index;
}

Long Line::Write(char* value) {
	CharacterFaces *instance = CharacterFaces::Instance();
	CharacterSize characterSize = instance->GetCharacterSize(KOREAN);
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

//ArrayIterator<Contents*>* Line::CreateIterator() const {
//	return Composite::CreateIterator();
//
////	return new ArrayIterator<Contents*>(&this->contents);
//}

//string Line::MakeLineString() {
//	string lineString;
//
//	ArrayIterator *i = static_cast<ArrayIterator*>(this->CreateIterator());
//
//	i->First();
//	while (i->IsDone() == false) {
//		if (dynamic_cast<SingleCharacter*>(i->GetCurrentItem())) { //this->GetCharacter(i->GetCurrent))) {
//			lineString += (dynamic_cast<SingleCharacter*>(i->GetCurrentItem()))->GetValue();
//		}
//		else if (dynamic_cast<DoubleCharacter*>(i->GetCurrentItem())) {
//			lineString += (dynamic_cast<DoubleCharacter*>(i->GetCurrentItem()))->GetValue()[0];
//			lineString += (dynamic_cast<DoubleCharacter*>(i->GetCurrentItem()))->GetValue()[1];
//		}
//		i->Next();
//	}
//	lineString += '\r';
//	lineString += '\n';
//	if (i != 0) {
//		delete i;
//		i = 0;
//	}
//	return lineString;

	//Character *characterLink;
	//Long i = 0;
	//while (i < this->length) {
	//	
	//	characterLink = this->GetCharacter(i);
	//	if (dynamic_cast<SingleCharacter*>(characterLink)) {
	//		lineString += (dynamic_cast<SingleCharacter*>(characterLink))->GetValue();
	//	}
	//	else if (dynamic_cast<DoubleCharacter*>(characterLink)) {
	//		lineString += (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue()[0];
	//		lineString += (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue()[1];
	//	}
	//	i++;
	//}
	//lineString += '\n';

	//return lineString;
//}
//
void Line::Accept(Visitor* visitor) {
	visitor->Visit(this);
}