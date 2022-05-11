#include "iter.hpp"
#define SIZ 4

template <typename T>
void iter(T *array, unsigned long siz, void (*exec)(T &))
{
	for (unsigned long i = 0; i < siz; i++)
	{
		if (array)
		{
			exec(array[i]);
		}
	}
}

void iter_int(int &elem) { std::cout << "<" << elem << "> "; }
void iter_float(float &elem) { std::cout << "<" << elem << "> "; }
void iter_char(char &elem) { std::cout << "<" << elem << "> "; }

template <typename T>
void iter_call(T &elem) { std::cout << "<" << elem << "> "; }

template <typename T>
void iter_inc(T &elem) { elem++; }

int main()
{
	int i_arr[SIZ] = {1, 2, 3, 4};
	float f_arr[SIZ] = {1.1f, 2.2f, 3.3f, 4.4f};
	char c_arr[SIZ] = {'a', 'b', 'c', 'd'};

	iter(i_arr, SIZ, iter_int);
	std::cout << "\n------------------------------\n";
	iter(f_arr, SIZ, iter_float);
	std::cout << "\n------------------------------\n";
	iter(c_arr, SIZ, iter_char);
	std::cout << "\n------------------------------\n";

	std::cout << "\nINCREMENT\n";
	iter(i_arr, SIZ, iter_inc);
	iter(f_arr, SIZ, iter_inc);
	iter(c_arr, SIZ, iter_inc);

	std::cout << "\nTEMPLATED\n";
	iter(i_arr, SIZ, iter_call);
	std::cout << "\n------------------------------\n";
	iter(f_arr, SIZ, iter_call);
	std::cout << "\n------------------------------\n";
	iter(c_arr, SIZ, iter_call);
	std::cout << "\n------------------------------\n";

	return (0);
}
