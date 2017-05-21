//CharacterFaces.cpp

#include "CharacterFaces.h"
#include <string>
#include <afxWin.h>
using namespace std;

CharacterFaces* CharacterFaces::instance = 0;

CharacterFaces::CharacterFaces()
	:characterSizes(96) {
	this->capacity = 96;	
	this->length = 0;
	this->fontFamily = "Tahoma";
	this->size = 500;
	CFont font;
	font.CreatePointFont(this->size, this->fontFamily.c_str());
	CDC dc;
	dc.SelectObject(&font);
	CSize size;
	char i = 32;
	while (i <= 126) {
		//subjectString = string(1, i);
		size = dc.GetTextExtent(CString(static_cast<char>(i)));
		CharacterSize characterSize(size.cx, size.cy);
		this->characterSizes.Store(this->length, characterSize);
		this->length++;
		i++;
	}
	size = dc.GetTextExtent(CString("��"));
	CharacterSize characterSize(size.cx, size.cy);
	this->characterSizes.Store(this->length, characterSize);
	this->length++;
}

CharacterFaces::CharacterFaces(const CharacterFaces& source)
	:characterSizes(source.characterSizes){
	this->instance = source.instance;
	this->size = source.size;
	this->capacity = source.capacity;
	this->length = source.length;
}

CharacterFaces::~CharacterFaces() {
	
}

CharacterSize& CharacterFaces::GetCharacterSize(Long nChar) {
	return this->characterSizes.GetAt(nChar-32);
}

CharacterFaces* CharacterFaces::Instance(){
	if(instance==0){
		instance = new CharacterFaces();
	}
	/*CFont font;
	font.CreatePointFont(instance->GetSize(), instance->GetFontFamily().c_str());
	dc->SelectObject(&font);*/
	return instance;
}

CharacterFaces& CharacterFaces::operator=(const CharacterFaces& source) {
	this->instance = source.instance;
	this->size = source.size;
	this->characterSizes = source.characterSizes;
	this->capacity = source.capacity;
	this->length = source.length;
	return *this;
}

CharacterSize& CharacterFaces::operator[](Long index) {
	return this->characterSizes[index];
}