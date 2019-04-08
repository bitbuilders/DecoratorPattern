#include "pch.h"
#include "DateFormatter.h"

std::string DateFormatter::Format(int mon, int day, int year, int hour, int min, int sec)
{
	std::string date = GetMonth(mon) + " " + std::to_string(day) + ", " + std::to_string(year + 1900);
	std::string time = SetLength(GetHour(hour)) + ":" + SetLength(std::to_string(min)) + ":" + SetLength(std::to_string(sec));

	return date + " " + time;
}

std::string DateFormatter::GetMonth(int mon)
{
	std::string month = "";

	if (mon == 0) month = "January";
	else if (mon == 1) month = "Febuary";
	else if (mon == 2) month = "March";
	else if (mon == 3) month = "April";
	else if (mon == 4) month = "May";
	else if (mon == 5) month = "June";
	else if (mon == 6) month = "July";
	else if (mon == 7) month = "August";
	else if (mon == 8) month = "September";
	else if (mon == 9) month = "October";
	else if (mon == 10) month = "November";
	else if (mon == 11) month = "December";

	return month;
}

std::string DateFormatter::GetHour(int hour)
{
	return std::to_string(hour % 12);
}

std::string DateFormatter::SetLength(std::string str, int length)
{
	int under = length - str.size();
	std::string s(under, '0');
	s += str;

	return s;
}
