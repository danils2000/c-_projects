#include <iostream>
#include <iomanip>
#include "time.h"
using namespace std;

void Time::read(const char* s) {
cout << s << " ";
cin >> hour >> min;
}

bool Time::lessThan(const Time &second) const {
	if (hour < second.hour || (hour == second.hour && min < second.min)) {
		return true;
	}
	else {
		return false;
	}
}

Time Time::subtract(const Time &x) const {
	Time time;
	int calc_min;
	calc_min = (hour * 60 + min) - (x.hour * 60 + x.min);
	time.hour = calc_min / 60;
	time.min = calc_min % 60;
	return time;
}

void Time::display() const {
	cout << hour << ':' << min << endl;
}

