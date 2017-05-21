//Character.cpp

#include "Character.h"

Character::Character(Long width, Long height) {
	this->width = width;
	this->height = height;
}

Character::~Character() {

}

Character::Character(const Character& source) {
	this->width = source.width;
	this->height = source.height;
}

Character& Character::operator=(const Character& source) {
	this->width = source.width;
	this->height = source.height;
	return *this;
}