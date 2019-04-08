#pragma once
#include "WriterDecorator.h"
class SignatureWriter : public WriterDecorator
{
public:
	SignatureWriter();
	SignatureWriter(const Writer* writer) : WriterDecorator(writer) {}
	~SignatureWriter();

	void Write(std::string file, std::string content) const;
};

