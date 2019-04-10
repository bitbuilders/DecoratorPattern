#pragma once
#include <string>

class Reader
{
public:
	Reader() { }

	virtual std::string Read(const std::string& file) const = 0;
	virtual void Destroy() = 0;
};

