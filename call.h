#pragma once

#include <string>

#define NUM_OFF 58
#define TYPE_OFF 8
#define DUR_OFF 101
#define TO_OFF 16

class call
{
	char *num;
	uint8_t _type;
	long duration;
	char *to;
	std::string out;
	std::string getRecipient();
public:
	call(char * record, int length);
	~call();
	std::string getRecord();
};

