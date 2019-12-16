#include "call.h"





call::call(char * record, int length)
{
	num = &record[NUM_OFF];
	_type = record[TYPE_OFF];
	duration = int(&record[DUR_OFF]);
}

call::~call()
{
}

std::string call::getRecord()
{
	switch (_type)
	{
	case 0x00:
		out.append("Dialed\t");
		break;
	case 0x80:
		out.append("Received\t");
		break;
	case 0x40:
		out.append("Missed\t");
		break;
	default:
		break;
	}

	if (_type == 0x00) {
		out.append("\t");
	}

	out.append(num);
	out.append("\n");

	return out;
}
