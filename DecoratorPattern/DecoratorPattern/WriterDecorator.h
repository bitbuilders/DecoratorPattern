#pragma once
#include "Writer.h"
class WriterDecorator : public Writer
{
public:
	WriterDecorator();
	WriterDecorator(const Writer* writer) { m_writer = writer; std::cout << "Wow that's neat!\n"; }
	~WriterDecorator();

protected:
	const Writer* m_writer;
};

