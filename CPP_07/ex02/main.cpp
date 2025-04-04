#include "Array.hpp"
#include <iostream>

int main() {
	try {
    Array<int> ints;
    // Fill the array with some values
    for (unsigned int i = 0; i < ints.size(); ++i) {
        ints[i] = i * 2; // Accessing through non-const version
    }
	const Array<int>& constArr = ints;
	// Print the array
	for (unsigned int i = 0; i < ints.size(); ++i) {
		std::cout << "Element at index " << i << ": " << ints[i] << std::endl; // Accessing through const version
	}
	std::cout << "Element at index 2: " << constArr[2] << std::endl; // Calls the const version

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

    return 0;
}
