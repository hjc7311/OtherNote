//SingleCharacter.cpp

#include "SingleCharacter.h"
#include "ArrayIterator.h"


SingleCharacter::SingleCharacter() {
	this->value = ' ';
}

SingleCharacter::SingleCharacter(char value) {
	this->value = value;
}

SingleCharacter::~SingleCharacter() {

}

Contents* SingleCharacter::Clone() {
	return new SingleCharacter(*this);
}

SingleCharacter::SingleCharacter(const SingleCharacter& source) {
	this->value = source.value;
}

SingleCharacter& SingleCharacter::operator=(const SingleCharacter& source) {
	this->value = source.value;

	return *this;
}

bool SingleCharacter::IsEqual(const SingleCharacter& other) {
	bool ret = false;
	if (this->value == other.value) {
		ret = true;
	}
	return ret;
}

bool SingleCharacter::IsNotEqual(const SingleCharacter& other) {
	bool ret = false;
	if (this->value != other.value) {
		ret = true;
	}
	return ret;
}

bool SingleCharacter::operator==(const SingleCharacter& other) {
	bool ret = false;
	if (this->value == other.value) {
		ret = true;
	}
	return ret;
}

bool SingleCharacter::operator!=(const SingleCharacter& other) {
	bool ret = false;
	if (this->value != other.value) {
		ret = true;
	}
	return ret;
}

ArrayIterator<Contents*>* SingleCharacter::CreateIterator() const {
	return 0;
}