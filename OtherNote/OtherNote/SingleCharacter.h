// SingleCharacter.h

#ifndef _SINGLECHARACTER_H
#define _SINGLECHARACTER_H

class SingleCharacter {
public :
	SingleCharacter();
	SingleCharacter(char value);
	~SingleCharacter();
	SingleCharacter(const SingleCharacter& source);
	SingleCharacter& operator=(const SingleCharacter& source);
	char GetValue() const;
private:
	char value;
};

inline char SingleCharacter::GetValue() const {
	return this->value;
}

#endif	//_SINGLECHARACTER_H
