#pragma once
#include "ReaderDecorator.h"
class ReadLineEndings : public ReaderDecorator
{
public:
	ReadLineEndings(Reader* reader) : ReaderDecorator(reader) { }
	
	std::string Read(const std::string& file) const;
};

