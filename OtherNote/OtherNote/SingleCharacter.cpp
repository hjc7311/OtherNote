//SingleCharacter.cpp

#include "SingleCharacter.h"

SingleCharacter::SingleCharacter()
	:Character() {
	this->value = ' ';
}

SingleCharacter::SingleCharacter(char value, Long width, Long height)
	: Character(width, height) {
	this->value = value;
}

SingleCharacter::SingleCharacter(const SingleCharacter& source)
	: Character(source) {
	this->value = source.value;
}

SingleCharacter::~SingleCharacter() {

}

SingleCharacter& SingleCharacter::operator=(const SingleCharacter& source) {
	Character::operator=(source);

	this->value = source.value;

	return *this;
}

//bool SingleCharacter::IsEqual(const SingleCharacter& other) {
//	bool ret = false;
//	if (this->value == other.value) {
//		ret = true;
//	}
//	return ret;
//}
//
//bool SingleCharacter::IsNotEqual(const SingleCharacter& other) {
//	bool ret = false;
//	if (this->value != other.value) {
//		ret = true;
//	}
//	return ret;
//}
//
//bool SingleCharacter::operator==(const SingleCharacter& other) {
//	bool ret = false;
//	if (this->value == other.value) {
//		ret = true;
//	}
//	return ret;
//}
//
//bool SingleCharacter::operator!=(const SingleCharacter& other) {
//	bool ret = false;
//	if (this->value != other.value) {
//		ret = true;
//	}
//	return ret;
//}

Contents* SingleCharacter::Clone() const {
	return new SingleCharacter(*this);
}

#include "Visitor.h"
void SingleCharacter::Accept(Visitor *visitor) {
	visitor->Visit(this);
}