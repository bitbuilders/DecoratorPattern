#pragma once
#include "Writer.h"

class WriterComponent : public Writer
{
public:
	WriterComponent() {}

	void Write(const std::string& file, const std::string& content) const;
	void Destroy() { }
};

