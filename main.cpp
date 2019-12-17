#include <iostream>
#include <fstream>
#include <sstream>
#include "call.h"

using namespace std;



int main(int argc, char* argv[])
{
	char *record = new char [LINE_SIZE];
	Call *callRec;

	ifstream calls("Calls.bin", ios::binary);
	ofstream txt("Calls.txt");

	if (calls.is_open())
	{
		txt << "Type\t\tTel From\tTel To\t\tTo\t\tDuration\n";		//print header
		while (calls.read(record, LINE_SIZE) && record[0] != 0x00)	//start reading binary
		{
			callRec = new Call(record, LINE_SIZE);					//create an object for each record
			txt << callRec->getType()
				<< callRec->getNumber()
				<< callRec->getDest()
				<< callRec->getDuration()
				<< endl;
			delete callRec;
		}

		calls.close();
		txt.close();
		
		
	}
	else cerr << "Error occurred opening the file\n";
	return 0;
}
