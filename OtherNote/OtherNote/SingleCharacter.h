// SingleCharacter.h

#ifndef _SINGLECHARACTER_H
#define _SINGLECHARACTER_H

#include "Character.h"

class SingleCharacter:public Character {
public :
	SingleCharacter();
	SingleCharacter(char value);
	virtual ~SingleCharacter();
	SingleCharacter(const SingleCharacter& source);
	SingleCharacter& operator=(const SingleCharacter& source);
	bool IsEqual(const SingleCharacter& source);
	bool IsNotEqual(const SingleCharacter& source);
	bool operator==(const SingleCharacter& source);
	bool operator!=(const SingleCharacter& source);
	char GetValue() const;
private:
	char value;
};

inline char SingleCharacter::GetValue() const {
	return this->value;
}

#endif	//_SINGLECHARACTER_H
