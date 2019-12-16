#include <iostream>
#include <fstream>
#include "call.h"

using namespace std;

#define LINE_SIZE 106

int main(int argc, char* argv[])
{
	//ios::pos_type size;
	char *record = new char [LINE_SIZE];
	call *callRec;
	
	

	ifstream calls("Calls.bin", ios::binary);
	ofstream txt("Calls.txt");

	if (calls.is_open())
	{
		while (calls.read(record, LINE_SIZE) && record[0] != 0x00)
		{
			callRec = new call(record, LINE_SIZE);
			txt << callRec->getRecord();
		}

		calls.close();
		txt.close();
		
		
	}
	else cerr << "Error occurred opening the file\n";
	return 0;
}
