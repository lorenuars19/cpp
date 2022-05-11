#include "serial.hpp"

uintptr_t serialize(Data *ptr)
{
	return ((uintptr_t)ptr);
}

Data *deserialize(uintptr_t raw)
{
	return ((Data *)raw);
}

std::ostream &operator<<(std::ostream &o, Data *data)
{
	if (!data)
	{
		return o << "Data NULL";
	}
	return o << "Data :" << std::dec
			 << " f(" << data->f
			 << ") c(" << data->c
			 << ") x(" << data->x
			 << ") y(" << data->y << ")";
}

int main()
{
	Data data;
	Data *new_data;
	uintptr_t raw;

	data = (Data){42.19, 's', 42, 19};

	std::cout << "Initial " << &data << std::endl;

	std::cout << "-------------------------------------\n";
	std::cout << "&data    : " << (void *)&data << std::endl;
	raw = serialize(&data);
	std::cout << "raw      : 0x" << std::hex << raw << std::endl;
	new_data = deserialize(raw);
	std::cout << "new_data : " << (void *)new_data << std::endl;
	std::cout << "-------------------------------------\n";

	std::cout << "Serialized " << new_data << std::endl;

	data.f = 1234.56789f;
	data.c = 'a';
	std::cout << "Changed    " << &data << std::endl;

	std::cout << "Serialized " << new_data << std::endl;
}
