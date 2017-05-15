//MakeStringVisitor.cpp
#include "MakeStringVisitor.h"
#include "Visitor.h"
#include "Memo.h"
#include "Line.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
typedef signed long int Long;

MakeStringVisitor::MakeStringVisitor() {

}
MakeStringVisitor::~MakeStringVisitor() {

}

MakeStringVisitor::MakeStringVisitor(const MakeStringVisitor& source) {

}
void MakeStringVisitor::Visit(Line *line) {
	Long i = 0;
	Character *character;
	while (i < line->GetLength()) {
		character = line->GetCharacter(i);
		if (dynamic_cast<SingleCharacter*>(character)) {
			this->str += dynamic_cast<SingleCharacter*>(character)->GetValue();
		}
		else if (dynamic_cast<DoubleCharacter*>(character)) {
			this->str += dynamic_cast<DoubleCharacter*>(character)->GetValue()[0];
			this->str += dynamic_cast<DoubleCharacter*>(character)->GetValue()[1];
		}
		i++;
	}
}

void MakeStringVisitor::Visit(Memo *memo) {
	Long i = 0;
	Long j;
	Line *line;
	while (i < memo->GetLength()) {
		line = memo->GetLine(i);
		j = 0;
		while (j < line->GetLength()) {
			if (dynamic_cast<SingleCharacter*>(line->GetCharacter(j))) {
				this->str += dynamic_cast<SingleCharacter*>(line->GetCharacter(j))->GetValue();
			}
			else if (dynamic_cast<DoubleCharacter*>(line->GetCharacter(j))) {
				this->str += dynamic_cast<DoubleCharacter*>(line->GetCharacter(i))->GetValue()[0];
				this->str += dynamic_cast<DoubleCharacter*>(line->GetCharacter(j))->GetValue()[1];
			}
			i++;
		}
		j++;
	}
}

void MakeStringVisitor::Visit(SingleCharacter *singleCharacter) {
	Long i = 0;
}
void MakeStringVisitor::Visit(DoubleCharacter *doubleCharaceter) {
	Long i = 0;
}

MakeStringVisitor& MakeStringVisitor::operator=(const MakeStringVisitor& source) {
	this->str = source.str;
	return *this;
}