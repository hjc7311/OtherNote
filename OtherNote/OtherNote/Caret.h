#pragma once
//Caret.h

#ifndef _CARET_H
#define _CARET_H

typedef signed long int Long;

class OtherNoteForm;
class Caret {
public:
	~Caret();
	static Caret* Instance(OtherNoteForm *otherNoteForm);
	void Move(Long xPosition, Long yPosition);
	void MovePreviousCharacter();
	void MoveNextCharacter();
	void MovePreviousLine();
	void MoveNextLine();
	void MovePreviousTab();
	void MoveNextTab();
	bool ChangeCaret();
	bool ChangeImeCaret();
	Long GetWidth() const;
	Long GetHeight() const;
	Long GetXPosition() const;
	Long GetYPosition() const;
protected:
	Caret(OtherNoteForm *otherNoteForm);
	Caret(const Caret& source);
	Caret& operator=(const Caret& source);
private:
	OtherNoteForm *otherNoteForm;
	Long width;
	Long height;
	Long xPosition;
	Long yPosition;
private:
	static Caret *_instance;
};

inline Long Caret::GetWidth() const {
	return this->width;
}

inline Long Caret::GetHeight() const {
	return this->height;
}

inline Long Caret::GetXPosition() const {
	return this->xPosition;
}

inline Long Caret::GetYPosition() const {
	return this->yPosition;
}

#endif	//_CARET_H