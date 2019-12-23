#pragma once

#include <string>

class alternread
{
protected:
	static std::string alt_read(char *ptr);
public:
	virtual std::string printHeader() = 0;
};

