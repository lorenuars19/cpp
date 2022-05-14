#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

typedef unsigned long u_long;

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "\033[91mError: invalid number of arguments\033[0m" << std::endl
				  << "	Usage: " << std::endl
				  << "		" << argv[0] << " [file] [s1] [s2]" << std::endl
				  << std::endl;
		return (1);
	}

	// convert argv[] array of char array to cpp strings
	std::string filename = std::string(argv[1]);
	std::string s1 = std::string(argv[2]);
	std::string s2 = std::string(argv[3]);

	// open input file for reading
	std::ifstream input_file(filename.c_str());
	if (!input_file.good())
	{
		std::cerr << "\033[91mError: " << filename
				  << " is not a valid readable file"
				  << "\033[0m" << std::endl;
		return (1);
	}
	// open ouput file for writing
	std::string outfile = filename + ".replace";
	std::ofstream output_file(outfile.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!output_file.good())
	{
		std::cerr << "\033[91mError: cannot open " << filename + ".replace"
				  << " for writing"
				  << "\033[0m" << std::endl;
		return (1);
	}
	std::cout << "SED s1 '" << s1 << "'"
			  << " s2 '" << s2 << "'"
			  << "\033[0m" << std::endl;
	// then output new file with replaced token

	bool ret = true;
	std::string filestr;
	while (input_file.good() && ret)
	{
		std::string tmp;

		ret = getline(input_file, tmp);
		filestr += tmp + "\n";
	}

	// find and replace occurence of s1 with s2 in file
	u_long start_pos = 0;
	u_long end_pos = 0;
	std::string substring;

	while (end_pos < filestr.size())
	{
		end_pos = filestr.find(s1, start_pos);
		if (end_pos >= std::string::npos)
		{
			end_pos = filestr.size();
		}
		substring = filestr.substr(start_pos, end_pos - start_pos);
		start_pos = end_pos;
		output_file << substring;
		std::cout << substring;
		if (end_pos < filestr.size())
		{
			output_file << s2;
			std::cout << s2;
			start_pos += s1.size();
		}
	}
	// close file handles & free memory etc ..
	input_file.close();
	output_file.close();

	return (0);
}
