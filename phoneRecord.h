#pragma once

#include <string>

class PhoneRecord
{
protected:
	static std::string alt_read(char *ptr);
public:
	virtual std::string printHeader() = 0;
	
	template <class T>
	std::string getAttr(T attribute);
};

