//Main.cpp

#include "SingleCharacter.h"
#include "DoubleCharacter.h"
#include "Line.h"
#include "Memo.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	Memo memo;
	Line *lineLink = new Line;
	
	Long index = memo.AddLine(lineLink);

	index = lineLink->Write('a');
	Character *characterLink = lineLink->GetCharacter(index);
	
	lineLink = new Line;
	index = memo.AddLine(lineLink);

	index = lineLink->Write("°¡");
	characterLink = lineLink->GetCharacter(index);

	lineLink = new Line;
	index = memo.AddLine(lineLink);

	index = lineLink->Write("°ª");
	characterLink = lineLink->GetCharacter(index);

	lineLink = new Line;
	index = memo.AddLine(lineLink);

	index = lineLink->Write('c');
	characterLink = lineLink->GetCharacter(index);

	Long i = 0;
	Long j;
	while (i < memo.GetLength()) {
		j = 0;
		lineLink = memo.GetLine(i);
		while (j < lineLink->GetLength()) {
			characterLink = lineLink->GetCharacter(j);
			if (dynamic_cast<SingleCharacter*>(characterLink)) {
				cout << (dynamic_cast<SingleCharacter*>(characterLink))->GetValue() << endl;
			}
			else if (dynamic_cast<DoubleCharacter*>(characterLink)) {
				char str[3];
				char *character = (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue();
				str[0] = character[0];
				str[1] = character[1];
				str[2] = '\0';
				cout << str << endl;
			}
			j++;
		}
		i++;
	}

	return 0;
}