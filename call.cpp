#include "call.h"





call::call(char * record, int length)
{
	num = &record[NUM_OFF];
	type = record[TYPE_OFF];
	duration = int(&record[DUR_OFF]);
}

call::~call()
{
}

std::string call::getRecord()
{
	switch (type)
	{
	case 0x00:
		out.append("Dialed");
	case 0x02:
		out.append("Received");
	case 0x04:
		out.append("Missed");
	default:
		break;
	}
	return out;
}
