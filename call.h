#pragma once

#include <string>

#define NUM_OFF 58
#define TYPE_OFF 8
#define DUR_OFF 101
#define TO_OFF 16

#define DIAL_ENC 0x00
#define MISS_ENC 0x40
#define RECV_ENC 0x80

enum class CallType : uint8_t
{
	Dialed = DIAL_ENC,
	Missed = MISS_ENC,
	Received = RECV_ENC
};

class Call
{
	CallType type;
	std::string number;
	char *to;
	std::string dest;
	long duration;

	void setRecipient();

public:
	Call(char * record, int length);
	~Call();
	std::string getRecord();
};

