#pragma once
#include <string>
#include <iostream>

class Writer
{
public:
	Writer() { }
	~Writer();

	virtual void Write(std::string file, std::string content) const = 0;
};

