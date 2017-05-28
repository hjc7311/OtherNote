// MakeStringVisitor.cpp

#include "MakeStringVisitor.h"
#include "Memo.h"
#include "Line.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"

MakeStringVisitor::MakeStringVisitor(){
	this->completeString = "";
}

MakeStringVisitor::MakeStringVisitor(const MakeStringVisitor& source){
	this->completeString = source.completeString;
}

MakeStringVisitor::~MakeStringVisitor(){

}

MakeStringVisitor& MakeStringVisitor::operator=(const MakeStringVisitor& source){
	this->completeString = source.completeString;

	return *this;
}

#include "ArrayIterator.h"
void MakeStringVisitor::Visit(Memo *memo) {
	ArrayIterator<Contents*> *memoIterator = static_cast<ArrayIterator<Contents*>*>(memo->CreateIterator());

	memoIterator->First();
	while (memoIterator->IsDone() != true) {
		MakeStringVisitor makeStringVisitor;
		static_cast<Line*>(memoIterator->CurrentItem())->Accept(&makeStringVisitor);

		this->completeString += makeStringVisitor.GetCompleteString();
		this->completeString += "\r\n";

		memoIterator->Next();
	}


	if (memoIterator != 0) {
		delete memoIterator;
		memoIterator = 0;
	}
}

void MakeStringVisitor::Visit(Line *line) {
	ArrayIterator<Contents*> *lineIterator = static_cast<ArrayIterator<Contents*>*>(line->CreateIterator());
	Character *characterLink;

	lineIterator->First();
	while (lineIterator->IsDone() != true) {
		characterLink = static_cast<Character*>(lineIterator->CurrentItem());
		if (dynamic_cast<SingleCharacter*>(characterLink)) {
			this->completeString += dynamic_cast<SingleCharacter*>(characterLink)->GetValue();
		}
		else if (dynamic_cast<DoubleCharacter*>(characterLink)) {
			this->completeString += dynamic_cast<DoubleCharacter*>(characterLink)->GetValue()[0];
			this->completeString += dynamic_cast<DoubleCharacter*>(characterLink)->GetValue()[1];
		}
		lineIterator->Next();
	}

	if (lineIterator != 0) {
		delete lineIterator;
		lineIterator = 0;
	}
}

void MakeStringVisitor::Visit(SingleCharacter *singleCharacter){

}

void MakeStringVisitor::Visit(DoubleCharacter *doubleCharacter){

}