#pragma once
#include <string>
class Brain {
public:
	Brain();
	Brain(const Brain &);
	Brain &operator=(const Brain &);
	~Brain();

private:
	std::string ideas[100];
};
