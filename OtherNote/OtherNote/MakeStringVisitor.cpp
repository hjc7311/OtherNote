// MakeStringVisitor.cpp

#include "MakeStringVisitor.h"
#include "Line.h"
#include "Memo.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
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

void MakeStringVisitor::Visit(Line *line){
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
}

void MakeStringVisitor::Visit(Memo *memo){
	Long i = 0;
	while(i < memo->GetLength()){
		MakeStringVisitor makeStringVisitor;
		memo->GetLine(i)->Accept(&makeStringVisitor);
		this->str += makeStringVisitor.GetStr();
		this->str += '\n';
		i++;
	}
}