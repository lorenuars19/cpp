#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

#define SET_PRINT " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
#define SET_INT "0123456789-+"
#define SET_DOUB "0123456789-+."

enum e_types
{
	TYP_DEFAULT = 'c',
	TYP_INT = 'i',
	TYP_FLOAT = 'f',
	TYP_DOUBLE = 'd'
};
#endif
