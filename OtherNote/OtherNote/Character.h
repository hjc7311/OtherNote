#pragma once
//Character.h

#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "Contents.h"

class Character : public Contents {

public:
	Character(Long width = 0, Long height = 0);
	Character(const Character& source);
	virtual ~Character() = 0;
	Character& operator=(const Character& source);
	Long GetWidth() const;
	Long GetHeight() const;
protected:
	Long width;
	Long height;
};

inline Long Character::GetWidth() const {
	return this->width;
}

inline Long Character::GetHeight() const {
	return this->height;
}

#endif	//_CHARACTER_H