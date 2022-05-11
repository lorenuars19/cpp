#ifndef SERIAL_HPP
#define SERIAL_HPP
#include <iomanip>
#include <iostream>
#include <stdint.h>

typedef struct s_data
{
	float f;
	char c;
	int x;
	int y;
} Data;

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif
