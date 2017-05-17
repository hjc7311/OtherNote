// MakeStringVisitor.cpp

#include "MakeStringVisitor.h"
#include "Line.h"
#include "Memo.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
#include "ArrayIterator.h"

typedef signed long int Long;

MakeStringVisitor::MakeStringVisitor(){
	this->str = "";
}

MakeStringVisitor::MakeStringVisitor(const MakeStringVisitor& source){
	this->str = source.str;
}

MakeStringVisitor::~MakeStringVisitor(){
}

MakeStringVisitor& MakeStringVisitor::operator=(const MakeStringVisitor& source){
	this->str = source.str;
	return *this;
}

void MakeStringVisitor::Visit(SingleCharacter *singleCharacter){
}

void MakeStringVisitor::Visit(DoubleCharacter *doubleCharacter){
}

void MakeStringVisitor::Visit(Line *line) {
	ArrayIterator<Contents*> *lineIterator = line->CreateIterator();
	Character *characterLink;

	lineIterator->First();
	while (lineIterator->IsDone() != true) {
		characterLink = static_cast<Character*>(lineIterator->CurrentItem());
		if (dynamic_cast<SingleCharacter*>(characterLink)) {
			this->str += dynamic_cast<SingleCharacter*>(characterLink)->GetValue();
		}
		else if (dynamic_cast<DoubleCharacter*>(characterLink)) {
			this->str += dynamic_cast<DoubleCharacter*>(characterLink)->GetValue()[0];
			this->str += dynamic_cast<DoubleCharacter*>(characterLink)->GetValue()[1];
		}
		lineIterator->Next();
	}
	
	if (lineIterator != 0) {
		delete lineIterator;
		lineIterator = 0;
	}
	
	/*
	Long i = 0;
	while(i < line->GetLength()){
		if(dynamic_cast<SingleCharacter*>(line->GetCharacter(i))){
			this->str += dynamic_cast<SingleCharacter*>(line->GetCharacter(i))->GetValue();
		}
		if(dynamic_cast<DoubleCharacter*>(line->GetCharacter(i))){
			this->str += dynamic_cast<DoubleCharacter*>(line->GetCharacter(i))->GetValue()[0];
			this->str += dynamic_cast<DoubleCharacter*>(line->GetCharacter(i))->GetValue()[1];
		}
		i++;
	}
	*/
}

void MakeStringVisitor::Visit(Memo *memo){
	ArrayIterator<Contents*> *memoIterator = memo->CreateIterator();
	//Line *linkLink;

	memoIterator->First();
	while (memoIterator->IsDone() != true) {
		MakeStringVisitor makeStringVisitor;
		static_cast<Line*>(memoIterator->CurrentItem())->Accept(&makeStringVisitor);
		
		this->str += makeStringVisitor.GetStr();
		this->str += '\n';

		memoIterator->Next();
	}


	if (memoIterator != 0) {
		delete memoIterator;
		memoIterator = 0;
	}
	
	/*
	Long i = 0;
	while(i < memo->GetLength()){
		MakeStringVisitor makeStringVisitor;
		memo->GetLine(i)->Accept(&makeStringVisitor);
		this->str += makeStringVisitor.GetStr();
		this->str += '\n';¤À
		i++;
	}
	*/
}