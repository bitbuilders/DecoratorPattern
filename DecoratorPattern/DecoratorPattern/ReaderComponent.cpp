#include "pch.h"
#include <iostream>
#include <fstream>
#include "ReaderComponent.h"

std::string ReaderComponent::Read(const std::string& file) const
{
	std::string text = "";

	std::ifstream myfile(file);
	std::string current;
	if (myfile.is_open()) 
	{
		while (std::getline(myfile, current)) 
		{
			text += current;
		}
	}

	return text;
}
