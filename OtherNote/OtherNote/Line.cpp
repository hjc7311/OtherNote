//Line.cpp

#include "Line.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"


Line::Line(Long capacity)
	:characters(capacity)
{
	this->capacity = capacity;
	this->length = 0;
}

Line::Line(const Line& source)
	:characters(source.characters) {
	this->capacity = source.capacity;
	this->length = source.length;
}

Line& Line::operator=(const Line& source) {
	Long i = 0;
	while (i < this->length) {
		delete this->characters[i];
		i++;
	}
	this->characters = source.characters;
	this->capacity = source.capacity;
	this->length = source.length;
	return *this;
}

Line::~Line() {
	Long i = 0;
	while (i < this->GetLength()) {
		delete this->characters.GetAt(i);
		i++;
	}
}

Long Line::Write(char value, Long column) {
	SingleCharacter *singleCharacter = new SingleCharacter(value);

	if (this->length < this->capacity) {
		column = this->characters.Store(column, singleCharacter);
	}
	else {
		column = this->characters.AppendFromRear(singleCharacter);
		this->capacity++;
	}
	this->length++;
	//column++;
	return column;
}

Long Line::Write(char* value, Long column) {
	DoubleCharacter *doubleCharacter = new DoubleCharacter(value);

	if (this->length < this->capacity) {
		column = this->characters.Store(column, doubleCharacter);
	}
	else {
		column = this->characters.AppendFromRear(doubleCharacter);
		this->capacity++;
	}
	this->length++;
	//column++;
	return column;
}

Character* Line::GetAt(Long index) {
	return this->characters.GetAt(index);
}

//2017/05/01 New
Long Line::Erase(Long index) {
	Character *characterLink(this->characters.GetAt(index));
	if (index >= 0) {
		if (characterLink != 0) {
			delete characterLink;
			characterLink = 0;
		}
		index = this->characters.Delete(index);
		this->capacity--;
		this->length--;
	}
	return index;
}

