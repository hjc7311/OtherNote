#pragma once
#pragma once
//CharacterFaces.h

#ifndef _CHARACTERFACES_H
#define _CHARACTERFACES_H

#include "Array.h"
#include"CharacterSize.h"
#include <string>
using namespace std;

typedef signed long int Long;

class CDC;
class CharacterFaces {
	static CharacterFaces* instance;
public:
	~CharacterFaces();
	static CharacterFaces* Instance(CDC *dc);
	//void CalculateSize(Long type, Long *width, Long *height);
	CharacterSize& GetCharacterSize(Long nChar);
	Long GetFontSize() const;
	Long GetCapacity() const;
	Long GetLength() const;
	string GetFontFamily() const;
	CharacterSize& operator[](Long index);
	void SetFontFamily(string fontFamily);
	void SetFontSize(Long FontSize);
protected:
	CharacterFaces(CDC *dc);
	CharacterFaces(const CharacterFaces& source);
	CharacterFaces& operator=(const CharacterFaces& source);
private:
	
	string fontFamily;
	Long fontSize;
	Array<CharacterSize> characterSizes;
	Long capacity;
	Long length;
};

inline Long CharacterFaces::GetFontSize() const {
	return this->fontSize;
}
inline Long CharacterFaces::GetCapacity() const {
	return this->capacity;
}

inline Long CharacterFaces::GetLength() const {
	return this->length;
}

inline string CharacterFaces::GetFontFamily() const {
	return this->fontFamily;
}


#endif	//_CHARACTERFACES_H