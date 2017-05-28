//CharacterFaces.cpp

#include "CharacterFaces.h"
#include <afxwin.h>

CharacterFaces* CharacterFaces::_instance = 0;

CharacterFaces::CharacterFaces(CDC *dc)
	:characterSizes(96) {
	this->capacity = 96;
	this->length = 0;
	this->size = 300;
	this->fontFamily = "Tahoma";

	CFont font;
	font.CreatePointFont(this->size, this->fontFamily.c_str());
	dc->SelectObject(&font);


	//
	//CFont *font = new CFont;
	//font->CreatePointFont(this->size, CString(this->fontFamily.c_str()));
	////font.CreatePointFont(300, "Tahoma");
	//dc->SelectObject(&font);


	//CFont font;
	//VERIFY(font.CreatePointFont(this->size, _T(this->fontFamily.c_str()), dc));
	

	// Do something with the font just created...
	//CFont* def_font = dc->SelectObject(&font);
	
	//dc->TextOut(5, 5, _T("Hello"), 5);
	
	// Done with the font. Delete the font object.
	//font->DeleteObject();

	Long i = 0;
	while (i <= 94) {
		CSize size(dc->GetTextExtent(static_cast<char>(i+32)));

		CharacterSize characterSize(size.cx, size.cy);
		this->characterSizes.Store(this->length, characterSize);

		this->length++;
		i++;
	}
	CSize size(dc->GetTextExtent(CString("°ª")));
	CharacterSize characterSize(size.cx, size.cy);
	this->characterSizes.Store(this->length, characterSize);
	this->length++;
}

CharacterFaces::CharacterFaces(const CharacterFaces& source)
	:characterSizes(source.characterSizes) {
	this->_instance = this;
	this->capacity = source.capacity;
	this->length = source.length;
	this->size = source.size;
}

CharacterFaces& CharacterFaces::operator=(const CharacterFaces& source)
{
	this->_instance = source._instance;
	this->characterSizes = source.characterSizes;
	this->capacity = source.capacity;
	this->length = source.length;
	this->size = source.size;

	return *this;
}

CharacterFaces* CharacterFaces::Instance(CDC *dc) {
	if (_instance == 0) {
		_instance = new CharacterFaces(dc);
	}

	//CFont font;
	//font.CreatePointFont(_instance->GetSize(), _instance->GetFontFamily().c_str());
	//dc->SelectObject(&font);
	
	return _instance;
}

CharacterFaces::~CharacterFaces() {
	_instance = 0;
}

CharacterSize& CharacterFaces::GetCharacterSize(Long nChar) {
	return const_cast<CharacterSize&>(this->characterSizes.GetAt(nChar-32));
}

CharacterSize& CharacterFaces::operator[](Long nChar) {
	return const_cast<CharacterSize&>(this->characterSizes[nChar-32]);
}