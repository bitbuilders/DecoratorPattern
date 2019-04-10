#pragma once
#include "WriterDecorator.h"
class WriteShiftUp : public WriterDecorator
{
public:
	WriteShiftUp(Writer* writer) : WriterDecorator(writer) { }

	void Write(const std::string& file, const std::string& content) const;
};

