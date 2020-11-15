#include <iostream>
#include <iomanip>
#include "Time.h"

using namespace std;

Time::Time(int hour0, int minute0) : hour(hour0), minute(minute0)
{
}

bool Time::operator<(const Time& secondTime) const
{
	return convert() < secondTime.convert();
}

Time Time::operator-(const Time& secondTime) const
{
	int diff = convert() - secondTime.convert();

	Time sub;
	sub.hour = diff / 60;
	sub.minute = diff % 60;

	return sub;
}

Time Time::operator+(const Time& secondTime) const
{
	int newConv = convert() + secondTime.convert();

	Time newTime;
	if (newConv >= 24 * 60) {
		newConv -= 24 * 60;
	}

	newTime.hour = newConv / 60;
	newTime.minute = newConv % 60;

	return newTime;
}

Time& Time::operator++()
{
	int converted = convert();
	converted++;

	if (converted == 24 * 60) {
		converted = 0;
	}

	hour = converted / 60;
	minute = converted % 60;

	return *this;
}

Time Time::operator++(int)
{
	Time copy = *this;

	int converted = convert();
	converted++;

	if (converted == 24 * 60) {
		converted = 0;
	}

	hour = converted / 60;
	minute = converted % 60;

	return copy;
}

bool Time::operator>(const Time& secondTime) const
{
	return convert() > secondTime.convert();
}

bool Time::operator==(const Time& secondTime) const
{
	return convert() == secondTime.convert();
}

ostream& operator<<(ostream& out, const Time& targetTime)
{
	out << setiosflags(ios::right); out << setfill('0') << setw(2) << targetTime.hour
		<< ":" << setfill('0') << setw(2) << targetTime.minute;
	return out;
}

istream& operator>>(istream& in, Time& targetTime)
{
	in >> targetTime.hour;

	if (in.peek() == ':') {
		in.ignore(1, ':');
		in >> targetTime.minute;
	}

	else {
		in.setstate(ios_base::failbit);
	}

	if (targetTime.hour > 23 || targetTime.minute > 59 || targetTime.hour < 0 || targetTime.minute < 0) {
		in.setstate(ios_base::failbit);
	}

	return in;
}

int Time::convert() const
{
	return hour * 60 + minute;
}