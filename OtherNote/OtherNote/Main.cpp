////Main.cpp
//
//#include "SingleCharacter.h"
//#include "DoubleCharacter.h"
//#include "Line.h"
//#include "Memo.h"
//#include "PaintVisitor.h"
//#include "MakeStringVisitor.h"
//#include <iostream>
//using namespace std;
//
//int main(int argc, char *argv[]) {
//
//	PaintVisitor paintVisitor;
//	Memo memo.Accept(&paintVisitor);
//
///*	Memo memo;
//	
//	Long index = memo.AddLine(lineLink);
//
//	index = lineLink->Write('a');
//	Character *characterLink = lineLink->GetCharacter(index);
//	
//	lineLink = new Line;
//	index = memo.AddLine(lineLink);
//
//	index = lineLink->Write("가");
//	characterLink = lineLink->GetCharacter(index);
//
//	lineLink = new Line;
//	index = memo.AddLine(lineLink);
//
//	index = lineLink->Write("값");
//	characterLink = lineLink->GetCharacter(index);
//
//	lineLink = new Line;
//	index = memo.AddLine(lineLink);
//
//	index = lineLink->Write('c');
//	characterLink = lineLink->GetCharacter(index);
//
//	Long i = 0;
//	Long j;
//	while (i < memo.GetLength()) {
//		j = 0;
//		lineLink = memo.GetLine(i);
//		while (j < lineLink->GetLength()) {
//			characterLink = lineLink->GetCharacter(j);
//			if (dynamic_cast<SingleCharacter*>(characterLink)) {
//				cout << (dynamic_cast<SingleCharacter*>(characterLink))->GetValue() << endl;
//			}
//			else if (dynamic_cast<DoubleCharacter*>(characterLink)) {
//				char str[3];
//				char *character = (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue();
//				str[0] = character[0];
//				str[1] = character[1];
//				str[2] = '\0';
//				cout << str << endl;
//			}
//			j++;
//		}
//		i++;
//	}
//
//	return 0;
//}
//*/


//Main.cpp
#include "Memo.h"
#include "Line.h"
#include "MakeStringVisitor.h"
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
	Memo memo;
	Long row = memo.GetRow();
	Line *lineLink = memo.GetLine(row);
	Long index = lineLink->Write('a');
	MakeStringVisitor makeStringVisitor;
	makeStringVisitor.Visit(lineLink);
	string str = makeStringVisitor.GetStr();
	cout << str << endl;

	Line line;
	row = memo.AddLine(&line);
	lineLink = memo.GetLine(row);
	index = lineLink->Write("한");
	index = lineLink->Write("글");
	MakeStringVisitor makeStringVisitor2;
	makeStringVisitor2.Visit(lineLink);
	string str2 = makeStringVisitor2.GetStr();
	cout << str2 << endl;


	return 0;
}