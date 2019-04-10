#pragma once
#include <string>
#include <iostream>

class Writer
{
public:
	Writer() { }

	virtual void Write(const std::string& file, const std::string& content) const = 0;
	virtual void Destroy() = 0;
};

