#include "contact.h"

std::string Contact::computePadLength(ContAttr attribute)
{
	std::string pad = "";
	switch (int(attributes[(int)attribute].length() / 8))
	{
	case 0:
		pad += "\t";
	case 1:
		pad += "\t";

	default:
		break;
	}
	return pad;
}

Contact::Contact(char *main, char* detail)
{
	ptr = &main[NAME_OFF];
	deleted = *ptr == 0x00 ? true : false;
	attributes[(int)ContAttr::Name] = alt_read(ptr);
	attributes[(int)ContAttr::Tel] = &main[TEL_OFF+deleted];
	if (!deleted) {
		attributes[(int)ContAttr::Home] = &detail[HOME_OFF];
		ptr = &detail[ORG_OFF];
		attributes[(int)ContAttr::Org] = alt_read(ptr);
		attributes[(int)ContAttr::Email] = &detail[MAIL_OFF];
		attributes[(int)ContAttr::Work] = &detail[WORK_OFF];
		attributes[(int)ContAttr::Fax] = &detail[FAX_OFF];
	}

}



std::string Contact::getAttr(ContAttr attribute)
{
	if (attribute == ContAttr::Deleted) {
		return deleted ? "Yes" : "";
	}
	else
	{
		std::string pad = computePadLength(attribute);
		return attributes[(int)attribute] + pad;
	}
	
}

std::string Contact::printHeader()
{
	return "Name\t\tTel\t\tFax\t\tHome\t\tWork\t\tEmail\t\t\tOrg\t\tDeleted\n";
}
