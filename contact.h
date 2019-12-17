#pragma once

#include <string>
#include "alternread.h"

#define MAIN_L 86
#define DATA_L 232

#define NAME_OFF 0
#define TEL_OFF 42
#define FAX_OFF 187
#define HOME_OFF 0
#define WORK_OFF 145
#define MAIL_OFF 84
#define ORG_OFF 42

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
	Contact(char *main, char *detail);
	~Contact();
	std::string getName();
	std::string getNumber();
	std::string getFax();
	std::string getHome();
	std::string getWork();
	std::string getMail();
	std::string getOrg();
	std::string getDel();
};

