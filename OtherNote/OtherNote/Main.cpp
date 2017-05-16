//Main.cpp

#include "SingleCharacter.h"
#include "DoubleCharacter.h"
#include "Line.h"
#include "Memo.h"
#include "MakeStringVisitor.h"
#include <iostream>
using namespace std;
typedef signed long int Long;

int main(int argc, char *argv[]) {
	Memo memo;
	memo.AddLine();
	Long row = memo.GetRow();
	Line *lineLink = memo.GetLine(row);
	Long index = lineLink->Write('a');
	MakeStringVisitor makeStringVisitor;
	makeStringVisitor.Visit(lineLink);
	string str = makeStringVisitor.GetStr();
	cout<<str<<endl;
	row = memo.AddLine();
	lineLink = memo.GetLine(row);
	lineLink->Write("วั");
	lineLink->Write("ฑÛ");
	makeStringVisitor.Visit(lineLink);
	str = makeStringVisitor.GetStr();
	cout<<str<<endl;


	
	return 0;
}