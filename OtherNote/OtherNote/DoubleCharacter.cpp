//DoubleCharacter.cpp

#include "DoubleCharacter.h"

DoubleCharacter::DoubleCharacter()
	:value("") {

}

DoubleCharacter::DoubleCharacter(string value)
	: value(value) {

}

DoubleCharacter::~DoubleCharacter() {

}

DoubleCharacter::DoubleCharacter(const DoubleCharacter& source)
	:value(source.value) {

}

DoubleCharacter& DoubleCharacter::operator=(const DoubleCharacter& source) {
	this->value = source.value;

	return *this;
}