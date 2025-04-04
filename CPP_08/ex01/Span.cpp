#include "Span.hpp"
Span::Span(unsigned int N)
{
	this->data_.reserve(N);//capacity
	this->maxNum_ = std::numeric_limits<int>::min();
	this->minNum_ = std::numeric_limits<int>::max();
	this->minDiff_ = std::numeric_limits<int>::max();
}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->data_ = other.data_;
		this->maxNum_ = other.maxNum_;
		this->minNum_ = other.minNum_;
		this->minDiff_ = other.minDiff_;
	}
	return *this;
}

Span::~Span()
{
	std::cout << "Destructor called" << std::endl;
}
void Span::addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	for(; first != last; first++)
		this->addNumber(*first);
}

 void Span::addNumbers(int elements, int value)
 {
	 for (int i = 0; i < elements; i++)
		 this->addNumber(value);
 }

void Span::addNumber(int number)
{
	if (this->data_.size() == this->data_.capacity())//size is returning not the index but the actual
		throw std::length_error("No more space in the container");
	if (number > this->maxNum_)
		this->maxNum_ = number;
	if (number < this->minNum_)
		this->minNum_ = number;
	//insertion_sort(this->data_.begin(), this->data_.end(), number);
	data_.push_back(number);
	size_t i = this->data_.size() - 1;
	while (i > 0 && this->data_[i] < this->data_[i - 1])
	{
		std::swap(this->data_[i], this->data_[i - 1]);
		i--;
	}
	if (i > 0)
		this->minDiff_ = std::min(this->minDiff_, this->data_[i] - this->data_[i - 1]);
	if (i < this->data_.size() - 1)
		this->minDiff_ = std::min(this->minDiff_, this->data_[i + 1] - this->data_[i]);

}

std::vector<int> Span::getData() const
{
	return this->data_;
}

int Span::longestSpan() const
{
	if (this->data_.size() < 2)
		throw std::range_error("Not enough elements in the container");
	int longest = this->maxNum_ - this->minNum_;
	return longest;
}

int Span::shortestSpan() const
{
	if (this->data_.size() < 2)
		throw std::range_error("Not enough elements in the container");
	return this->minDiff_;
}
