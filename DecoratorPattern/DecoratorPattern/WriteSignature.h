#pragma once
#include "WriterDecorator.h"
class WriteSignature : public WriterDecorator
{
public:
	WriteSignature(Writer* writer) : WriterDecorator(writer) {}

	void Write(const std::string& file, const std::string& content) const;
};

