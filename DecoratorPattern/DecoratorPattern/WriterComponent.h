#pragma once
#include "Writer.h"

class WriterComponent : public Writer
{
public:
	WriterComponent() {}
	~WriterComponent();

	void Write(std::string file, std::string content) const;
};

