#include "pch.h"
#include "WriterComponent.h"
#include <fstream>


WriterComponent::~WriterComponent()
{
}

void WriterComponent::Write(std::string file, std::string content) const
{
	std::ofstream myfile;
	myfile.open(file);
	myfile << content;
	myfile.close();
	
	std::cout << "WriterComponent Write\n";
}
