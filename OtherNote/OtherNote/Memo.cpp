//Memo.cpp
//test

#include "Memo.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
#include <iostream>

Memo::Memo(Long capacity)
	:lines(capacity) {
	this->capacity = capacity;
	this->length = 0;
	this->row = 0;
	this->column = 0;
}

Memo::Memo(const Memo& source)
	:lines(source.lines)
{
	this->capacity = source.capacity;
	this->length = source.length;
	this->row = source.row;
	this->column = source.column;
}

Memo::~Memo() {
}

void Memo::Write(char value) {
	Line *line = &this->lines.GetAt(this->row);
	this->column = line->Write(value, this->column);
	this->column++;
}

void Memo::Write(char* value) {
	Line *lineLink = &this->lines.GetAt(this->row);
	this->column = lineLink->Write(value, this->column);
	this->column++;
}

Line& Memo::GetAt(Long row) {
	return this->lines.GetAt(row);
}

//2017/05/01 New
Long Memo::Erase() {
	Long index = 0;
	
	Line *lineLink = &this->lines.GetAt(this->row);

	if (lineLink->GetLength() >= 2) {
		this->column--;
		index = lineLink->Erase(this->column);
	}
	else if (lineLink->GetLength() == 1) {
		this->column--;
		index = lineLink->Erase(this->column);
		if (this->length >= 2) {//라인의 개수는 무조건 1개 이상을 가져야 한다가 기본이다.
			this->lines.Delete(this->row);
			this->row--;
			this->column = this->lines.GetAt(this->row).GetLength();
		}
	}
	return index;
}

