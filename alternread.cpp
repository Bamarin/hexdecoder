#include "alternread.h"




std::string alternread::alt_read(char * ptr)
{
	std::string ret;
	do
	{
		ret.append(ptr);
		ptr += 2;
	} while (*ptr != 0x00);
	return ret;
}
