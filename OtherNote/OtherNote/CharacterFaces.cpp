//CharacterFaces.cpp

#include "CharacterFaces.h"
#include <string>
#include <afxWin.h>
using namespace std;

CharacterFaces* CharacterFaces::instance = 0;

CharacterFaces::CharacterFaces(CDC *dc)
	:characterSizes(96) {
	this->capacity = 96;	
	this->length = 0;
	this->fontFamily = "Tahoma";
	this->fontSize = 600;
	CFont font;
	font.CreatePointFont(this->fontSize, this->fontFamily.c_str());
	dc->SelectObject(&font);
	Long i = 0;
	while (i <= 94) {
		CSize csize = dc->GetTextExtent(CString(static_cast<char>(i+32)));
		CharacterSize characterSize(csize.cx, csize.cy);
		this->characterSizes.Store(this->length, characterSize);
		this->length++;
		i++;
	}
	CSize csize = dc->GetTextExtent(CString("°ª"));
	CharacterSize characterSize(csize.cx, csize.cy);
	this->characterSizes.Store(this->length, characterSize);
	this->length++;
}

CharacterFaces::CharacterFaces(const CharacterFaces& source)
	:characterSizes(source.characterSizes){
	this->instance = source.instance;
	this->fontSize = source.fontSize;
	this->capacity = source.capacity;
	this->length = source.length;
}

CharacterFaces::~CharacterFaces() {
	
}

CharacterSize& CharacterFaces::GetCharacterSize(Long nChar) {
	return this->characterSizes.GetAt(nChar-32);
}

CharacterFaces* CharacterFaces::Instance(CDC *dc){
	if(instance==0){
		instance = new CharacterFaces(dc);
	}
	/*CFont font;
	font.CreatePointFont(instance->GetSize(), instance->GetFontFamily().c_str());
	dc->SelectObject(&font);*/
	return instance;
}

CharacterFaces& CharacterFaces::operator=(const CharacterFaces& source) {
	this->instance = source.instance;
	this->fontSize = source.fontSize;
	this->characterSizes = source.characterSizes;
	this->capacity = source.capacity;
	this->length = source.length;
	return *this;
}

CharacterSize& CharacterFaces::operator[](Long nChar) {
	return const_cast<CharacterSize&>(this->characterSizes[nChar-32]);
}

void CharacterFaces::SetFontFamily(string fontFamily) {
	this->fontFamily = fontFamily;
}

void CharacterFaces::SetFontSize(Long fontSize) {
	this->fontSize = fontSize;
}