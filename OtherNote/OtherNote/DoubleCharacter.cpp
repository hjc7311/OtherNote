//DoubleCharacter.cpp

#include "DoubleCharacter.h"

DoubleCharacter::DoubleCharacter()
{
	this->value[0] = ' ';
	this->value[1] = ' ';
}

DoubleCharacter::DoubleCharacter(char* value)
{
	this->value[0] = value[0];
	this->value[1] = value[1];
}

DoubleCharacter::~DoubleCharacter() {

}

DoubleCharacter::DoubleCharacter(const DoubleCharacter& source)
{
	this->value[0] = source.value[0];
	this->value[1] = source.value[1];
}

DoubleCharacter& DoubleCharacter::operator=(const DoubleCharacter& source) {
	this->value[0] = source.value[0];
	this->value[1] = source.value[1];

	return *this;
}
