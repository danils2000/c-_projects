#include <iostream>
using namespace std;

class Time {
public:
	void read(const char *number);
	bool lessThan(Time t);
	Time subtract(Time x);
	void display();

private:
	int hour = 0;
	int min = 0;
};


void Time::read(const char *number) {
	cout << number << endl;
	cin >> hour;
	cin >> min;
}

bool Time::lessThan(Time second) {
	if (hour < second.hour || (hour == second.hour && min < second.min)) {
		return true;
	}
	else {
		return false;
	}
}

Time Time::subtract(Time x) {
	Time time;
	int calc_min;
	calc_min = (hour * 60 + min) - (x.hour * 60 + x.min);
	time.hour = calc_min / 60;
	time.min = calc_min % 60;
	return time;
}

void Time::display() {
	cout << hour << ':' << min << endl;
}


int main() {
	Time time1, time2, duration;

	time1.read("Enter time 1");
	time2.read("Enter time 2");
	if (time1.lessThan(time2)) {
		duration = time2.subtract(time1);
		cout << "Starting time was ";
		time1.display();
	} else {
		duration = time1.subtract(time2);
		cout << "Starting time was ";
		time2.display();
	}
	cout << "Duration was ";
	duration.display();

	return 0;
}
