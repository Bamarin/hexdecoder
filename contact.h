#pragma once

#include <string>
#include "alternread.h"

#define MAIN_L 86

#define NAME_OFF 0
#define TEL_OFF 42

class Contact : public alternread
{
	char *record;
	char *ptr;
	std::string name;
	std::string tel;
	std::string fax;
	std::string home;
	std::string work;
	std::string mail;
	std::string org;
	bool deleted;

public:
	Contact(char *record);
	~Contact();
	std::string getName();
	std::string getNumber();
	std::string getDel();
};

