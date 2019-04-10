#include "pch.h"
#include "WriteSignature.h"
#include "DateFormatter.h"
#include <ctime>

void WriteSignature::Write(const std::string& file, const std::string& content) const
{
	time_t now = std::time(0);
	tm* local = std::localtime(&now);
	std::string date = DateFormatter::Format(local->tm_mon, local->tm_mday, local->tm_year, local->tm_hour, local->tm_min, local->tm_sec);
	std::string signature = "\rColin Misbach - " + date;

	if (m_writer) m_writer->Write(file, content + signature);
}