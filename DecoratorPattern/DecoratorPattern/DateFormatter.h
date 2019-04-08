#pragma once
#include <string>

class DateFormatter
{
public:
	static std::string Format(int mon, int day, int year, int hour, int min, int sec);

private:
	DateFormatter() {}

	static std::string GetMonth(int mon);
	static std::string GetHour(int hour);
	static std::string SetLength(std::string str, int length = 2);
};

