#include <sstream>  
#include <iostream>
#include <chrono>
#include "call.h"

std::string seconds2HMS(int seconds) {	//could be improved with c++20 using formatter
	std::chrono::seconds sec(seconds);
	std::chrono::minutes min;
	std::chrono::hours hours;
	std::string HMS = "";
	hours = std::chrono::duration_cast<std::chrono::hours>(sec);
	HMS += std::to_string(hours.count()) + ":";
	sec -= hours;
	min = std::chrono::duration_cast<std::chrono::minutes>(sec);
	HMS += std::to_string(min.count()) + ":";
	sec -= min;
	HMS += std::to_string(sec.count());
	return HMS;
}

void Call::setRecipient()
{
	dest = alt_read(to);
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
		return seconds2HMS(duration);
	else return "";
}

Call::Call(char * record)
{
	type = (CallType)record[TYPE_OFF];
	number = &record[NUM_OFF];
	to = &record[TO_OFF];
	this->setRecipient();
	duration = record[DUR_OFF];
}

std::string Call::getAttr(CallAttr attribute)
{
	switch (attribute)
	{
	case CallAttr::Type:
		return this->getType();
	case CallAttr::Number:
		return this->getNumber();
	case CallAttr::To:
		return this->getDest();
	case CallAttr::Duration:
		return this->getDuration();
	default:
		break;
	}
}

std::string Call::printHeader()
{
	return "Type\t\tTel From\tTel To\t\tTo\t\tDuration\n";
}



