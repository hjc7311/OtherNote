//DoubleCharacter.cpp

#include "DoubleCharacter.h"
#include "ArrayIterator.h"

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

Contents* DoubleCharacter::Clone() {
	return new DoubleCharacter(*this);
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