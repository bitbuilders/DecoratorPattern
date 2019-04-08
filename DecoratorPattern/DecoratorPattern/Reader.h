#pragma once
#include <string>

class Reader
{
public:
	Reader(const Reader& reader) { m_reader = &reader; }
	~Reader();

	virtual void Read(std::string file) = 0;

protected:
	const Reader* m_reader;
};

