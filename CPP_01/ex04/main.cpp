
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " needed 3 parameters" << std::endl;
		return 1;
	}
	std::string input_file = argv[1];
	std::string s1, s2;
	s1 = argv[2];
	s2 = argv[3];
	if (input_file.empty() || s1.empty())
	{
		std::cerr << "Invalid input" << std::endl;
		return 1;
	}


	std::ifstream from(input_file.c_str());
	if (!from)
	{
		std::cerr << "Can't open file " << input_file << std::endl;
		return 1;
	}

	std::ofstream to((input_file + ".replace").c_str());
	if (!to)
	{
		from.close();
		std::cerr << "Can't open file " << input_file + ".replace" << std::endl;
		return 1;
	}
	std::string line;
	size_t pos = 0;
	while (std::getline(from, line))
	{
		std::string modified_line;
		size_t last_pos = 0;

		while ((pos = line.find(s1, last_pos)) != std::string::npos )//TODO deside what to do
		{
			modified_line.append(line, last_pos, pos- last_pos);
			modified_line += s2;
			last_pos = pos + s1.length();
		}
		modified_line += line.substr(last_pos);
		to << modified_line << std::endl;
	}
	from.close();
	to.close();
}
