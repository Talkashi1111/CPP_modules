#include "ford_johnson.hpp"

RecursivePair::RecursivePair(int leader, RecursivePair *first, RecursivePair *second)
	: _leader(leader), _first(first), _second(second)
{
}

void PrintPairs(std::vector<RecursivePair> &pairs)
{
	std::cout << "Leaders" << pairs.size() << ": ";
	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		std::cout << pairs[i]._leader << " ";
	}
	std::cout << std::endl;
}

// Function to get the n-th Jacobsthal number
// Jacobsthal numbers are defined as follows: J(n) = (2^n - (-1)^n) / 3
int GetJacobsthalNumber(int n)
{
	return (pow(2, n) - (n % 2 == 0 ? 1 : -1)) / 3;
}
static void BinaryInsertion(std::vector<RecursivePair> &pairs, RecursivePair &b_pair, int i, int &prev)
{
	int left = 0;
	int right = i - 1;//starting (for B5 from A4)
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (b_pair._leader < pairs[mid]._leader)
		{
			right = mid - 1;
		}
		else//if B i greater or equal to A
		{
			left = mid + 1;
		}
	}
	pairs.insert(pairs.begin() + left, b_pair);
	if (left <= prev)//in a case b_pair._leader is less than or equal to prev
	{
		prev++;
	}
}

static std::vector<RecursivePair> ConstructPairs(std::vector<RecursivePair> &pairs)
{
	std::vector<RecursivePair> new_pairs;
	new_pairs.reserve(pairs.size());
	for (std::size_t i = 0; i < pairs.size() - 1; i += 2)
	{
		if (pairs[i]._leader < pairs[i + 1]._leader)
		{
			std::swap(pairs[i], pairs[i + 1]);
		}
		int leader = pairs[i]._leader;
		RecursivePair new_pair(leader, &pairs[i], &pairs[i + 1]);
		new_pairs.push_back(new_pair);
	}
	return new_pairs;
}

static std::vector<RecursivePair> MergeInsertion(std::vector<RecursivePair> &pairs)
{
	if (pairs.size() < 2)
	{
		return pairs;
	}
	std::vector<RecursivePair> new_pairs = ConstructPairs(pairs);
	new_pairs = MergeInsertion(new_pairs);
	int j_num = 2;//starting from 3rd Jacobsthal number which is 1
	int curr = 0;//previous + (difference between current and previous Jacobsthal number)
	int prev = -1;//-1 to initialize the first iteration
	while (curr > prev)
	{
		int i = curr;
		while (i > prev)//going back till we reach prev jacobsthal
		{
			if (new_pairs[i]._second == NULL)//if second is null meaning that we found a B and not A.(null is the indicator)
			{
				i--;
				continue;
			}
			RecursivePair b_pair(new_pairs[i]._second->_leader, new_pairs[i]._second, NULL);//exctracting B from A
			new_pairs[i]._second = NULL;//setting A second to null to indicate that B is already sorted
			curr++;
			// We don't update i because we insert new element at pos < i
			// so i will automatically point to the element before i before the insertion
			// so we basically do i++ and i-- at the end of iteration
			BinaryInsertion(new_pairs, b_pair, i, prev);
		}
		j_num++;
		prev = curr;
		curr = prev + GetJacobsthalNumber(j_num) - GetJacobsthalNumber(j_num - 1);
		curr = std::min(curr, static_cast<int>(new_pairs.size() - 1));
	}
	if (pairs.size() % 2 != 0)//check for tail (1 or 0)
	{
		RecursivePair b_pair(pairs[pairs.size() - 1]._leader, &pairs[pairs.size() - 1], NULL);//wrap  it and binary insert
		BinaryInsertion(new_pairs, b_pair, new_pairs.size(), prev);
	}
	std::vector<RecursivePair> final_pairs;//generate a copy of the final pairs to avoid shalow copy
	final_pairs.reserve(new_pairs.size());//only availible for vector
	for (std::size_t i = 0; i < new_pairs.size(); ++i)
	{
		final_pairs.push_back(*new_pairs[i]._first);
	}
	return final_pairs;
}

void StartMergeInsertion(std::vector<int> &elems)
{
	std::vector<RecursivePair> pairs;
	pairs.reserve(elems.size());
	for (std::size_t i = 0; i < elems.size(); ++i)
	{
		RecursivePair pair(elems[i], NULL, NULL);
		pairs.push_back(pair);
	}
	pairs = MergeInsertion(pairs);
	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		elems[i] = pairs[i]._leader;
	}
}
