#include "call.h"


void Call::setRecipient()
{

	while (*to != 0x00)
	{
		dest.append(to);
		to += 2;
	}
}

Call::Call(char * record, int length)
{
	type = (CallType)record[TYPE_OFF];
	number = &record[NUM_OFF];
	to = &record[TO_OFF];
	setRecipient();
	duration = long(&record[DUR_OFF]);
}

Call::~Call()
{
}

std::string Call::getRecord()
{
	std::string out;

	switch (type)
	{
	case CallType::Dialed:
		out.append("Dialed\t\t");
		break;
	case CallType::Received:
		out.append("Received\t");
		break;
	case CallType::Missed:
		out.append("Missed\t\t");
		break;
	default:
		break;
	}

	if (type == CallType::Dialed) {
		out.append("\t\t");
	}

	out.append(number);
	number.length() > 7 ? out.append("\t") : out.append("\t\t");
	out.append(dest);
	out.append("\n");

	return out;
}
