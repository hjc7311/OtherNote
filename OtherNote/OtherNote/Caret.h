#pragma once
//Caret.h

#ifndef _CARET_H
#define _CARET_H

//#include <afxwin.h>
//using namespace std;

typedef signed long int Long;

class NoteBookForm;
class Caret {
public:
	~Caret();
	static Caret* Instance(NoteBookForm *noteBookForm);
	void Move(Long xPos, Long yPos);
	void MoveNextCharacter();
	void MovePreviousCharacter();
	void MoveNextLine();
	void MovePreviousLine();
	bool ChangeCaret();
	bool ChangeImeCaret();
	void MoveNextTab();
	void MovePreviousTab();
	//static void SetCaretPosition(NoteBookForm *noteBookForm, Long xPosition, Long yPosition);
	Long GetWidth() const;
	Long GetHeight() const;
	Long GetXPosition() const;
	Long GetYPosition() const;
protected:
	Caret(NoteBookForm *noteBookForm);
	Caret(const Caret& source);
	Caret& operator=(const Caret& source);

//public:
//	static Long width;
//	static Long height;
//	static Long xPosition;
//	static Long yPosition;

private:
	Long width;
	Long height;
	Long xPosition;
	Long yPosition;
	NoteBookForm *noteBookFormLink;
private:
	static Caret *_instance;
//	static NoteBookForm *noteBookFormLink;
	
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