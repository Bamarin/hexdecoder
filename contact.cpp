#include "contact.h"

Contact::Contact(char *main, char* detail)
{
	ptr = &main[NAME_OFF];
	deleted = *ptr == 0x00 ? true : false;
	name = alt_read(ptr);
	tel = &main[TEL_OFF+deleted];
	if (!deleted) {
		home = &detail[HOME_OFF];
		ptr = &detail[ORG_OFF];
		org = alt_read(ptr);
		mail = &detail[MAIL_OFF];
		work = &detail[WORK_OFF];
		fax = &detail[FAX_OFF];
	}

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

std::string Contact::getFax()
{
	return fax;
}

std::string Contact::getHome()
{
	return home;
}

std::string Contact::getWork()
{
	return work;
}

std::string Contact::getMail()
{
	return mail;
}

std::string Contact::getOrg()
{
	return org;
}

std::string Contact::getDel()
{
	return deleted ? "Yes" : "" ;
}
