#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "call.h"
#include "contact.h"

using namespace std;



int main(int argc, char* argv[])
{
	char *record = new char[LINE_SIZE];
	char *main_rec = new char[MAIN_L];
	char *data_rec = new char[DATA_L];
	Call *callRec = new Call();
	Contact *contRec = new Contact();

	ifstream calls("Calls.bin", ios::binary);
	ofstream txt("Calls.txt");

	if (calls.is_open())
	{
		txt << callRec->printHeader();		
		while (calls.read(record, LINE_SIZE) && record[0] != 0x00)	//start reading binary
		{
			callRec = new Call(record);					//create an object for each record
			txt << callRec->getAttr(CallAttr::Type)					//print it to a file
				<< callRec->getAttr(CallAttr::Number)
				<< callRec->getAttr(CallAttr::To)
				<< callRec->getAttr(CallAttr::Duration)
				<< endl;
			delete callRec;
		}

		calls.close();
		txt.close();
		
	}
	else cerr << "Error occurred opening the file Calls.bin" << endl;
	delete record;

	ifstream p_main("Phonebook_Main.bin", ios::binary);
	ifstream p_data("Phonebook_Details.bin", ios::binary);
	txt.open("Phonebook.txt");

	if (p_main.is_open())
	{
		txt << contRec->printHeader();
		while (p_main.read(main_rec, MAIN_L) && p_data.read(data_rec,DATA_L) && main_rec[MAIN_L-1] != 0x00)
		{
			contRec = new Contact(main_rec, data_rec);
			txt << contRec->getAttr(ContAttr::Name)
				<< contRec->getAttr(ContAttr::Tel)
				<< contRec->getAttr(ContAttr::Fax)
				<< contRec->getAttr(ContAttr::Home)
				<< contRec->getAttr(ContAttr::Work)
				<< contRec->getAttr(ContAttr::Email) << "\t"
				<< contRec->getAttr(ContAttr::Org)
				<< contRec->getAttr(ContAttr::Deleted)
				<< endl;
			delete contRec;
		}
		p_main.close();
		p_data.close();
		txt.close();
	}
	else cerr << "Error occurred opening the file Calls.bin" << endl;
	delete main_rec;
	delete data_rec;

	return 0;
}
