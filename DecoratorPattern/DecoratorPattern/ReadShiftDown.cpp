#include "pch.h"
#include "ReadShiftDown.h"

std::string ReadShiftDown::Read(const std::string& file) const
{
	std::string encoded = "";
	if (m_reader) 
	{
		std::string content = m_reader->Read(file);
		for (int i = 0; i < content.size(); i++) 
		{
			if (content[i] == ' ' || content[i] == '\n' || content[i] == '\r')
			{
				encoded += content[i];
			}
			else
			{
				encoded += content[i] - 1;
			}
		}
	}

	return encoded;
}
