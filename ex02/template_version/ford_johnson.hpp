#pragma once

#include <iterator>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm> // For std::swap()
#include <cmath>	 // For pow()

struct RecursivePair
{
	int _leader; // The maximum value at this level
	RecursivePair *_first;
	RecursivePair *_second;

	RecursivePair(int leader, RecursivePair *first, RecursivePair *second);
};

int GetJacobsthalNumber(int n);

template <template <typename, typename> class Container>
void PrintElements(
	const Container<int, std::allocator<int> > &elems,
	const std::string &msg)
{
	typedef typename Container<int, std::allocator<int> >::const_iterator ConstIterator;

	std::cout << msg;
	for (ConstIterator it = elems.begin(); it != elems.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <template <typename, typename> class Container>
void PrintPairs(Container<RecursivePair, std::allocator<RecursivePair> > &pairs)
{
	std::cout << "Leaders" << pairs.size() << ": ";
	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		std::cout << pairs[i]._leader << " ";
	}
	std::cout << std::endl;
}
template <template <typename, typename> class Container>
void BinaryInsertion(
	Container<RecursivePair, std::allocator<RecursivePair> > &pairs,
	RecursivePair &b_pair, int i, int &prev)
{
	int left = 0;
	int right = i - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (b_pair._leader < pairs[mid]._leader)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	pairs.insert(pairs.begin() + left, b_pair);
	if (left <= prev)
	{
		prev++;
	}
}

template <template <typename, typename> class Container>
Container<RecursivePair, std::allocator<RecursivePair> > ConstructPairs(
	Container<RecursivePair, std::allocator<RecursivePair> > &pairs)
{
	Container<RecursivePair, std::allocator<RecursivePair> > new_pairs;
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

template <template <typename, typename> class Container>
Container<RecursivePair, std::allocator<RecursivePair> > MergeInsertion(
	Container<RecursivePair, std::allocator<RecursivePair> > &pairs)
{
	if (pairs.size() < 2)
	{
		return pairs;
	}
	Container<RecursivePair, std::allocator<RecursivePair> > new_pairs = ConstructPairs(pairs);
	new_pairs = MergeInsertion(new_pairs);
	int j_num = 2;
	int curr = 0;
	int prev = -1;
	while (curr > prev)
	{
		int i = curr;
		while (i > prev)
		{
			if (new_pairs[i]._second == NULL)
			{
				i--;
				continue;
			}
			RecursivePair b_pair(new_pairs[i]._second->_leader, new_pairs[i]._second, NULL);
			new_pairs[i]._second = NULL;
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
	if (pairs.size() % 2 != 0)
	{
		RecursivePair b_pair(pairs[pairs.size() - 1]._leader, &pairs[pairs.size() - 1], NULL);
		BinaryInsertion(new_pairs, b_pair, new_pairs.size(), prev);
	}
	Container<RecursivePair, std::allocator<RecursivePair> > final_pairs;
	for (std::size_t i = 0; i < new_pairs.size(); ++i)
	{
		final_pairs.push_back(*new_pairs[i]._first);
	}
	return final_pairs;
}

template <template <typename, typename> class Container>
void StartMergeInsertion(Container<int, std::allocator<int> > &elems)
{
	Container<RecursivePair, std::allocator<RecursivePair> > pairs;
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
