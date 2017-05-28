//Visitor.cpp

#include "Visitor.h"

Visitor::Visitor() {

}

Visitor::~Visitor() {

}

Visitor::Visitor(const Visitor& source) {

}

Visitor& Visitor::operator=(const Visitor& source) {
	return *this;
}

void Visitor::Visit(SingleCharacter *singleCharacter) {

}

void Visitor::Visit(DoubleCharacter *doubleCharacter) {

}

void Visitor::Visit(Memo *memo) {

}

void Visitor::Visit(Line *line) {
	
}