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

enum class AttrType : uint8_t
{
	Name = 0,
	Tel,
	Fax,
	Home,
	Work,
	Email,
	Org,
	Deleted
};

class Contact : public alternread
{
	char *record;
	char *ptr;
	bool deleted;
	std::string attributes [8];
	std::string computePadLength(AttrType attribute);

public:
	Contact(char *main, char *detail);
	~Contact();

	std::string getAttr(AttrType attribute);
};

