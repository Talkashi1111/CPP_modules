#include "ford_johnson.hpp"
#include <sstream>

RecursivePair::RecursivePair(int leader, RecursivePair *first, RecursivePair *second)
	: _leader(leader), _first(first), _second(second)
{
}

// Function to get the n-th Jacobsthal number
// Jacobsthal numbers are defined as follows: J(n) = (2^n - (-1)^n) / 3
int GetJacobsthalNumber(int n)
{
	return (pow(2, n) - (n % 2 == 0 ? 1 : -1)) / 3;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
		return 0;
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
				std::cerr << "Error" << std::endl;
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
	std::cout << "Time to process a range of "<< numbers_copy.size() << " elements with std::[vector] : "<< time_measure << " us" << std::endl;


	std::deque<int> deque_numbers(numbers.begin(), numbers.end());
	PrintElements(deque_numbers, "Before: ");
	start_time = clock();
	StartMergeInsertion(deque_numbers);
	end_time = clock();
	time_measure = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000000;
	PrintElements(deque_numbers, "After: ");
	std::cout << "Time to process a range of "<< deque_numbers.size() << " elements with std::[deque] : "<< time_measure << " us" << std::endl;
}
/*
linux command for generating numbers and proccessing to the executable:
 ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
*/
