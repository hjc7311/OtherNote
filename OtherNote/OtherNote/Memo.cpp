//Memo.cpp

#include "Memo.h"
#include "iostream"

Memo::Memo(Long capacity)
	:singleCharacters(capacity)	{
	this->singleCharacters.Store(0, SingleCharacter(0));
	this->capacity = capacity;
	this->length = 0;
}

Memo::~Memo() {

}
//
Long Memo::Write(char value) {
//Long Memo::Write(){

	Long index = this->length;
/*
	char value;
	scanf("%c", &value);
	*/
	
	if (this->length < this->capacity) {
		this->singleCharacters.Store(index, SingleCharacter(value));
		this->length++;
	}
	return index;
}

SingleCharacter& Memo::GetAt(Long index) {
	return this->singleCharacters.GetAt(index);
}

#include <iostream>
using namespace std;

int main(int argc, char argv[]) {
	Memo memo(10);
	
	Long index = memo.Write('a');
/*
	SingleCharacter singleCharacter(memo.GetAt(index));
	
	cout << singleCharacter.GetValue() << endl;
*/

	cout << memo.GetAt(index).GetValue() << endl;

	index = memo.Write('b');
	cout << memo.GetAt(index).GetValue() << endl;

	cout << memo.GetAt(5).GetValue() << endl;


	return 0;
}