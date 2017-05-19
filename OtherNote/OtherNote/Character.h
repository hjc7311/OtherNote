#pragma once
//Character.h

#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "Contents.h"

class Character :public Contents {
public:
	Character();
	virtual ~Character() = 0;
};



#endif	//_CHARACTER_H