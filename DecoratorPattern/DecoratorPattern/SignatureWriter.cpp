#include "pch.h"
#include "SignatureWriter.h"
#include "DateFormatter.h"
#include <ctime>

SignatureWriter::SignatureWriter()
{
}


SignatureWriter::~SignatureWriter()
{
}

void SignatureWriter::Write(std::string file, std::string content) const
{
	time_t now = std::time(0);
	tm* local = std::localtime(&now);
	std::string signature = "\nColin Misbach - " + DateFormatter::Format(local->tm_mon, local->tm_mday, local->tm_year, local->tm_hour, local->tm_min, local->tm_sec);

	if (m_writer != nullptr) m_writer->Write(file, content + signature);

	std::cout << "Signature stamped!\n";
}
