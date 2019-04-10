#include "pch.h"
#include "WriteShiftUp.h"

void WriteShiftUp::Write(const std::string& file, const std::string& content) const
{
	std::string encoded = "";
	for (int i = 0; i < content.size(); i++) 
	{
		if (content[i] == ' ' || content[i] == '\n' || content[i] == '\r')
		{
			encoded += content[i];
		}
		else
		{
			encoded += content[i] + 1;
		}
	}
	
	if (m_writer) m_writer->Write(file, encoded);
}
