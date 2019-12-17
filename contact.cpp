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
	std::string pad;
	pad = name.length() < 8 ? "\t" : "";
	return name + pad;
}

std::string Contact::getNumber()
{
	std::string pad;
	pad = tel.length() < 8 ? "\t" : "";
	return tel + pad;
}

std::string Contact::getFax()
{
	std::string pad;
	pad = fax.length() < 8 ? "\t" : "";
	return fax + pad;
}

std::string Contact::getHome()
{
	std::string pad;
	pad = home.length() < 8 ? "\t" : "";
	return home + pad;
}

std::string Contact::getWork()
{
	std::string pad;
	pad = work.length() < 8 ? "\t" : "";
	return work + pad;
}

std::string Contact::getMail()
{
	std::string pad="";
	switch (int(mail.length()/8))
	{
	case 0:
		pad += "\t";
	case 1:
		pad += "\t";

	default:
		break;
	}
	return mail + pad;
}

std::string Contact::getOrg()
{
	std::string pad;
	pad = org.length() < 8 ? "\t" : "";
	return org + pad;
}

std::string Contact::getDel()
{
	return deleted ? "Yes" : "" ;
}
