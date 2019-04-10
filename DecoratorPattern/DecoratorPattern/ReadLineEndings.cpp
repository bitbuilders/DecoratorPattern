#include "pch.h"
#include <iostream>
#include "ReadLineEndings.h"

std::string ReadLineEndings::Read(const std::string & file) const
{
	std::string converted = "";
	if (m_reader)
	{
		std::string content = m_reader->Read(file);
		for (int i = 0; i < content.size(); i++)
		{
			if (content[i] == '\r')
			{
				converted += '\n';
			}
			else
			{
				converted += content[i];
			}
		}
	}

	return converted;
}
