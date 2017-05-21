//SingleCharacter.cpp

#include "SingleCharacter.h"
#include "ArrayIterator.h"
#include "Visitor.h"


SingleCharacter::SingleCharacter() 
	:Character(){
	this->value = ' ';
}

SingleCharacter::SingleCharacter(char value, Long width, Long height) 
	:Character(width, height){
	this->value = value;
}

SingleCharacter::~SingleCharacter() {

}

Contents* SingleCharacter::Clone() const {
	return new SingleCharacter(*this);
}

SingleCharacter::SingleCharacter(const SingleCharacter& source) 
	:Character(source){
	this->value = source.value;
}

SingleCharacter& SingleCharacter::operator=(const SingleCharacter& source) {
	Character::operator=(source);
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

void SingleCharacter::Accept(Visitor *visitor) {
	visitor->Visit(this);
}