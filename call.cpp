#include <sstream>  
#include "call.h"

void Call::setRecipient()
{
	dest = alt_read(to);
}



Call::Call(char * record)
{
	type = (CallType)record[TYPE_OFF];
	number = &record[NUM_OFF];
	to = &record[TO_OFF];
	this->setRecipient();
	duration = record[DUR_OFF];
}


std::string Call::getType()
{
	switch (this->type)
	{
	case CallType::Dialed:
		return "Dialed\t\t";
	case CallType::Received:
		return "Received\t";
	case CallType::Missed:
		return "Missed\t\t";
	default:
		return "Undef.\t\t";
	}
}

std::string Call::getNumber()
{
	std::string ret;

	if (type == CallType::Dialed) {
		ret = "\t\t" + number;
	}
	else {
		ret = number + "\t\t";
	}
	ret += (number.length() > 7) ?  "\t" : "\t\t";

	return ret;
}

std::string Call::getDest()
{
	if (dest == "")
		return "\t\t";
	else return dest;
}

std::string Call::getDuration()
{
	if (duration>0)
		return std::to_string(duration);
	else return "";
}

std::string Call::printHeader()
{
	return "Type\t\tTel From\tTel To\t\tTo\t\tDuration\n";
}



