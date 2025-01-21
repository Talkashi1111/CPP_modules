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

void StartMergeInsertion(std::vector<int> &elems);
void StartMergeInsertion(std::deque<int> &elems);
int GetJacobsthalNumber(int n);
