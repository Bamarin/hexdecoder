#include "call.h"





std::string call::getRecipient()
{
	std::string out;

	while (*to != 0x00)
	{
		out.append(to);
		to += 2;
	}
	return out;
}

call::call(char * record, int length)
{
	num = &record[NUM_OFF];
	_type = record[TYPE_OFF];
	duration = long(&record[DUR_OFF]);
	to = &record[TO_OFF];
}

call::~call()
{
}

std::string call::getRecord()
{
	switch (_type)
	{
	case 0x00:
		out.append("Dialed\t\t");
		break;
	case 0x80:
		out.append("Received\t");
		break;
	case 0x40:
		out.append("Missed\t\t");
		break;
	default:
		break;
	}

	if (_type == 0x00) {
		out.append("\t\t");
	}

	out.append(num);
	num[7] == 0x00 ? out.append("\t\t") : out.append("\t");
	out.append(this->getRecipient());
	out.append("\n");

	return out;
}
