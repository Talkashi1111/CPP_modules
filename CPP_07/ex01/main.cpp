#include "iter.hpp"
#include <iterator>


template <typename T>
void addedOneNprint(T &array)
{
	//array = array + 1;//risk for overflow?
	std::cout << array << std::endl;
}

void printInt(int x) {
    std::cout << x << " ";
}

double printDouble(double x) {
    std::cout << x << " ";
	return x;
}

int main(void)
{
	int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << "Int array: ";
    iter(intArray, 5, printInt);
    std::cout << "\nDouble array: ";
    iter(doubleArray, 5, printDouble);


	int arr[] = {1, 2, 3};
	size_t size = sizeof(arr) / sizeof(arr[0]);
	std::cout << "Size: " << size << std::endl;
	//iter(arr, size, addedOneNprint);
	std::string my_strings[] = {"lets", "try" , "this", "mother" , "fuckers"};
	my_strings[1] = my_strings[1] + '1';
	size_t size_s = my_strings->size();
	std::cout << "Size is %d " <<  size_s << std::endl;
	//::iter(my_strings, size, addedOneNprint);
}
