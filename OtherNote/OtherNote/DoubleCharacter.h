#pragma once
//DoubleCharacter.h

#ifndef _DOUBLECHARACTER_H
#define _DOUBLECHARACTER_H

#include "Character.h"
#include <string>
using namespace std;

class DoubleCharacter :public Character {
public:
	DoubleCharacter();
	DoubleCharacter(string value);
	virtual ~DoubleCharacter();
	DoubleCharacter(const DoubleCharacter& source);
	DoubleCharacter& operator=(const DoubleCharacter& source);
	bool IsEqual(const DoubleCharacter& source);
	bool IsNotEqual(const DoubleCharacter& source);
	bool operator==(const DoubleCharacter& source);
	bool operator!=(const DoubleCharacter& source);
	string& GetValue() const;
private:
	string value;
};

inline string& DoubleCharacter::GetValue() const {
	return const_cast<string&>(this->value);
}

#endif	//_DOUBLECHARACTER_H