//Memo.cpp

#include "Memo.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
#include <iostream>

Memo::Memo(Long capacity)
	:characters(capacity)
{
	this->capacity = capacity;
	this->length = 0;
}

Memo::~Memo() {
	Long i = 0;
	while (i < this->GetLength()) {
		delete this->characters.GetAt(i);
		i++;
	}
}

Long Memo::Write(char value) {
	Long index = this->length;

	SingleCharacter *singleCharacter = new SingleCharacter(value);

	if (this->length < this->capacity) {
		index=this->characters.Store(index, singleCharacter);
	}
	else {
		index=this->characters.AppendFromRear(singleCharacter);
		this->capacity++;
	}
	this->length++;

	return index;
}

Long Memo::Write(char* value) {
	Long index = this->length;
	
	DoubleCharacter *doubleCharacter = new DoubleCharacter(value);

	if (this->length < this->capacity) {
		index = this->characters.Store(index, doubleCharacter);
	}
	else {
		index = this->characters.AppendFromRear(doubleCharacter);
		this->capacity++;
	}
	this->length++;

	return index;
}

Character* Memo::GetAt(Long index) {
	return this->characters.GetAt(index);
}

//2017/05/01 New
Long Memo::Erase(Long index) {
	Character *characterLink(this->characters.GetAt(index));
	if (index >= 0) {
		if (characterLink != 0) {
			delete characterLink;
			characterLink = 0;
		}
		index = this->characters.Delete(index);
		this->capacity--;
		this->length--;
	
	}
	return index;
}

//Long Memo::Write(wchar_t value) {
//	Long index = this->length;
//
//	DoubleCharacter *doubleCharacter = new DoubleCharacter();
//
//	if (this->length < this->capacity) {
//		this->characters.Store(index, doubleCharacter);
//		this->length++;
//	}
//	return index;
//}



//
//#include <iostream>
//using namespace std;
//int main(int argc, char argv[]) {
//	Memo memo(100);
//	
//	Long index = memo.Write('°¡');
//
//	Character* characterLink = memo.GetAt(index);
//	if (dynamic_cast<SingleCharacter*>(characterLink)) {
//		cout << (dynamic_cast<SingleCharacter*>(characterLink))->GetValue() << endl;
//	}
//	else if (dynamic_cast<DoubleCharacter*>(characterLink)) {
//		cout << (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue() << endl;
//	}
//	return 0;
//}