#pragma once
#include "Writer.h"
class WriterDecorator : public Writer
{
public:
	WriterDecorator(Writer* writer) { m_writer = writer; }

	virtual void Write(const std::string& file, const std::string& content) const = 0;
	inline void Destroy() 
	{
		if (m_writer) m_writer->Destroy();
		delete m_writer;
	}

protected:
	Writer* m_writer;
};

