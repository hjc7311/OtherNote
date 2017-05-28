//DoubleCharacter.cpp

#include "DoubleCharacter.h"
#include "ArrayIterator.h"
#include "Visitor.h"

DoubleCharacter::DoubleCharacter()
	:Character() {
	this->value[0] = ' ';
	this->value[1] = ' ';
}

DoubleCharacter::DoubleCharacter(char* value, Long width, Long height)
	:Character(width,height) {
	this->value[0] = value[0];
	this->value[1] = value[1];
}

DoubleCharacter::~DoubleCharacter() {

}

Contents* DoubleCharacter::Clone() const{
	return new DoubleCharacter(*this);
}

DoubleCharacter::DoubleCharacter(const DoubleCharacter& source)
	:Character(source)
{
	this->value[0] = source.value[0];
	this->value[1] = source.value[1];
}

void DoubleCharacter::Accept(Visitor *visitor) {
	visitor->Visit(this);
}

DoubleCharacter& DoubleCharacter::operator=(const DoubleCharacter& source)
{
	Character::operator=(source);
	this->value[0] = source.value[0];
	this->value[1] = source.value[1];

	return *this;
}

bool DoubleCharacter::IsEqual(const DoubleCharacter& other) {
	bool ret = false;
	if (this->value[0] == other.value[0] && this->value[1] == other.value[1]) {
		ret = true;
	}
	return ret;
}

ArrayIterator<Contents*>* DoubleCharacter::CreateIterator() const {
	return 0;
}

bool DoubleCharacter::IsNotEqual(const DoubleCharacter& source) { return false; }
bool DoubleCharacter::operator==(const DoubleCharacter& source){ return false; }
bool DoubleCharacter::operator!=(const DoubleCharacter& source){ return false; }