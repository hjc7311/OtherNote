//SingleCharacter.cpp

#include "SingleCharacter.h"

SingleCharacter::SingleCharacter() {
	this->value = ' ';
}

SingleCharacter::SingleCharacter(char value) {
	this->value = value;
}

SingleCharacter::~SingleCharacter() {

}

SingleCharacter::SingleCharacter(const SingleCharacter& source) {
	this->value = source.value;
}

SingleCharacter& SingleCharacter::operator=(const SingleCharacter& source) {
	this->value = source.value;
	return *this;
}