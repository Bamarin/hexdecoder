#pragma once

#include <string>

#define NUM_OFF 58
#define TYPE_OFF 8
#define DUR_OFF 101

class call
{
	char *num;
	uint8_t _type;
	long duration;
	std::string out;
public:
	call(char * record, int length);
	~call();
	std::string getRecord();
};

