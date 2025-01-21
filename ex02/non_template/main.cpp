#include "ford_johnson.hpp"
#include <sstream>

void PrintElements(const std::vector<int> &elems, const std::string &msg)
{
	std::cout << msg;
	for (std::vector<int>::const_iterator it = elems.begin(); it != elems.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PrintElements(const std::deque<int> &elems, const std::string &msg)
{
	std::cout << msg;
	for (std::deque<int>::const_iterator it = elems.begin(); it != elems.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		return 0;
	}
	std::vector<int> numbers;
	for (int i = 1; i < argc; ++i)
	{
		std::istringstream iss(argv[i]);
		std::string token;

		// Split each argument (handles quoted inputs)
		while (iss >> token)
		{
			int num;
			std::istringstream numStream(token);
			if (!(numStream >> num) || num < 0)
			{
				std::cerr << "Error: Invalid number in input" << std::endl;
				return 1;
			}
			numbers.push_back(num);
		}
	}
	std::vector<int> numbers_copy(numbers.begin(), numbers.end());
	PrintElements(numbers_copy, "Before: ");
	clock_t start_time = clock();
	StartMergeInsertion(numbers_copy);
	clock_t end_time = clock();
	double time_measure = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000000;
	PrintElements(numbers_copy, "After: ");
	std::cout << "\n\nTime taken for vector ford-johnsohn sorting : " << time_measure << " us" << std::endl;


	std::deque<int> deque_numbers(numbers.begin(), numbers.end());
	PrintElements(deque_numbers, "Before: ");
	start_time = clock();
	StartMergeInsertion(deque_numbers);
	end_time = clock();
	time_measure = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000000;
	PrintElements(deque_numbers, "After: ");
	std::cout << "\n\nTime taken for deque ford-johnsohn sorting : " << time_measure << " us" << std::endl;
}
