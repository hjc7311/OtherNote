#pragma once
//Character.h

#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "Contents.h"

//typedef long int Long;
class Character :public Contents {
public:
	Character();
	virtual ~Character() = 0;
	Character(const Character& source);
	Character& operator=(const Character& source);

//	Long GetWidth() const;
//	Long GetHeight() const;
//protected:
//	Long width;
//	Long height;
};

//inline Long Character::GetWidth() const {
//	return this->width;
//}
//
//inline Long Character::GetHeight() const {
//	return this->height;
//}


#endif	//_CHARACTER_H