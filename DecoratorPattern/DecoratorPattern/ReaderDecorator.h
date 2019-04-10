#pragma once
#include "Reader.h"

class ReaderDecorator : public Reader
{
public:
	ReaderDecorator(Reader* reader) { m_reader = reader; }

	std::string Read(const std::string& file) const = 0;
	inline void Destroy() 
	{
		if (m_reader) m_reader->Destroy();
		delete m_reader;
	}

protected:
	Reader* m_reader;
};

