#pragma once
//CharacterFaces.h

#ifndef _CHARACTERFACES_H
#define _CHARACTERFACES_H

#include "CharacterSize.h"
#include "Array.h"
#include <string>
using namespace std;

class CDC;
class CharacterFaces {
public:
	~CharacterFaces();
	static CharacterFaces* Instance(CDC *dc);
	CharacterSize& GetCharacterSize(Long nChar);
	CharacterSize& operator[](Long nChar);

	Long GetCapacity() const;
	Long GetLength() const;
	Long GetSize() const;
	string& GetFontFamily() const;
protected:
	CharacterFaces(CDC *dc = 0);
	CharacterFaces(const CharacterFaces& source);
	CharacterFaces& operator=(const CharacterFaces& source);
private:
	static CharacterFaces *_instance;
	Array<CharacterSize> characterSizes;
	Long capacity;
	Long length;
	Long size;
	string fontFamily;
};

inline Long CharacterFaces::GetCapacity() const {
	return this->capacity;
}

inline Long CharacterFaces::GetLength() const {
	return this->length;
}

inline Long CharacterFaces::GetSize() const {
	return this->size;
}

inline string& CharacterFaces::GetFontFamily() const{
	return const_cast<string&>(this->fontFamily);
}

#endif	//_CHARACTERFACES_H