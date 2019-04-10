#pragma once
#include "ReaderDecorator.h"
class ReadShiftDown : public ReaderDecorator
{
public:
	ReadShiftDown(Reader* reader) : ReaderDecorator(reader) { }

	std::string Read(const std::string& file) const;
};

