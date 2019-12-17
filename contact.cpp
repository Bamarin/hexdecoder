#include "contact.h"

Contact::Contact(char *record)
{
	ptr = &record[NAME_OFF];
	deleted = *ptr == 0x00 ? true : false;
	name = alt_read(ptr);
	tel = &record[TEL_OFF+deleted];
}

Contact::~Contact()
{
}

std::string Contact::getName()
{
	return name;
}

std::string Contact::getNumber()
{
	return tel;
}

std::string Contact::getDel()
{
	return deleted ? "Yes" : "" ;
}
