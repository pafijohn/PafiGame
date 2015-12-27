#include "Endianness.h"

/**
 * @brief Determines at run-time if the program is running on a little endian system.
 * @return If the program is running on a little endian system.
 */
bool IsLittleEndian()
{
	enum
	{
		NOT_DEFINED,
		LITTLE,
		BIG
	};

	static int endian = NOT_DEFINED;
	
	if (endian == NOT_DEFINED)
	{
		union
		{
			unsigned int i;
			char c[4];
		} bint;
		
		bint.i = 0x01020304;
		endian = bint.c[0] == 1 ? BIG : LITTLE;
	}
	
	return endian == LITTLE;
}
