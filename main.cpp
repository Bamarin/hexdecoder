#include <iostream>
#include <fstream>
#include <sstream>
#include "call.h"
#include "contact.h"

using namespace std;



int main(int argc, char* argv[])
{
	char *record = new char [LINE_SIZE];
	Call *callRec;
	Contact *contRec;

	ifstream calls("Calls.bin", ios::binary);
	ofstream txt("Calls.txt");

	if (calls.is_open())
	{
		txt << "Type\t\tTel From\tTel To\t\tTo\t\tDuration\n";		//print header
		while (calls.read(record, LINE_SIZE) && record[0] != 0x00)	//start reading binary
		{
			callRec = new Call(record);					//create an object for each record
			txt << callRec->getType()					//print it to a file
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
	delete record;
	record = new char[MAIN_L];

	ifstream p_main("Phonebook_Main.bin", ios::binary);
	ifstream p_data("Phonebook_Details.bin", ios::binary);
	txt.open("Phonebook.txt");

	if (p_main.is_open())
	{
		while (p_main.read(record, MAIN_L) && record[MAIN_L-1] != 0x00)
		{
			contRec = new Contact(record);
			txt << contRec->getName()
				<< contRec->getNumber()

				<< contRec->getDel()
				<< endl;
			delete contRec;
		}
		p_main.close();
		p_data.close();
		txt.close();
	}
	return 0;
}
