#pragma once
#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <iostream>

class Time {
	friend std::ostream& operator<<(std::ostream& out, const Time& targetTime);
	friend std::istream& operator>>(std::istream& in, Time& targetTime);
public:
	Time(int hour0 = 0, int minute0 = 0);
	bool operator<(const Time& secondTime) const;
	Time operator-(const Time& secondTime) const;
	Time operator+(const Time& secondTime) const;
	bool operator>(const Time& secondTime) const;
	bool operator==(const Time& secondTime) const;
	Time& operator++();
	Time operator++(int);
private:
	int hour;
	int minute;
	int convert() const;
};

#endif