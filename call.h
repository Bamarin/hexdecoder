#pragma once

#include <string>

#define LINE_SIZE 106

#define TYPE_OFF 8
#define NUM_OFF 58
#define TO_OFF 16
#define DUR_OFF 100

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
	int duration;

	void setRecipient();
	void typeToString();

public:
	Call(char * record, int length);
	~Call();
	std::string getType();
	std::string getNumber();
	std::string getDest();
	std::string getDuration();
};

