#include <iostream>
#include <fstream>

using namespace std;

#define LINE_SIZE 106

int main(int argc, char* argv[])
{
	//ios::pos_type size;
	char * record = new char [LINE_SIZE];
	char * num = record+58;
	

	ifstream calls("Calls.bin", ios::binary);
	ofstream txt("Calls.txt");

	if (calls.is_open())
	{
		do
		{
			calls.read(record, LINE_SIZE);
			txt << num << '\n';
		} while (record[0] != 0x00);
		calls.close();
		txt.close();
		
		
	}
	else cerr << "Error occurred opening the file\n";
	return 0;
}
