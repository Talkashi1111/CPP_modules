#pragma once

#include <string>

class Weapon
{
public:
	Weapon(std::string w_name);
	const std::string &getType() const;
	void setType(std::string new_type);
	// Weapon();
	~Weapon(); //??
private:
	std::string type;
};
