#include "pch.h"
#include "WriterComponent.h"
#include <fstream>

void WriterComponent::Write(const std::string& file, const std::string& content) const
{
	std::ofstream myfile;
	myfile.open(file);
	myfile << content;
	myfile.close();
}
