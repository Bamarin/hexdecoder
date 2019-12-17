#include <iostream>
#include <fstream>
#include "call.h"

using namespace std;

#define LINE_SIZE 106

int main(int argc, char* argv[])
{
	char *record = new char [LINE_SIZE];
	Call *callRec;
	
	

	ifstream calls("Calls.bin", ios::binary);
	ofstream txt("Calls.txt");

	if (calls.is_open())
	{
		txt << "Type\t\tTel From\tTel To\t\tTo\t\tDuration\n";
		while (calls.read(record, LINE_SIZE) && record[0] != 0x00)
		{
			callRec = new Call(record, LINE_SIZE);
			txt << callRec->getRecord();
			delete callRec;
		}

		calls.close();
		txt.close();
		
		
	}
	else cerr << "Error occurred opening the file\n";
	return 0;
}
