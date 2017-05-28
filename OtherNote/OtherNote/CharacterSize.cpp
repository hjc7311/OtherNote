//CharacterSize.cpp

#include "CharacterSize.h"

CharacterSize::CharacterSize() {
	this->width = 0;
	this->height = 0;
}

CharacterSize::CharacterSize(Long width, Long height) {
	this->width = width;
	this->height = height;
}

CharacterSize::CharacterSize(const CharacterSize& source) {
	this->width = source.width;
	this->height = source.height;
}

CharacterSize& CharacterSize::operator=(const CharacterSize& source) {
	this->width = source.width;
	this->height = source.height;
	
	return *this;
}

CharacterSize::~CharacterSize() {

}

