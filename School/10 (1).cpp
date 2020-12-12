#include <iostream>
using namespace std;

class Counter {
public:
	virtual void inc() = 0;
	virtual void dec() = 0;
	virtual operator int() = 0;
	virtual ~Counter() {};
};

class LimitedCounter : public Counter {
public:
	void inc();
	void dec();
	operator int();
	LimitedCounter(int ctr = 0, int maxx = 10);
private:
	int count;
	int max;
};

void LimitedCounter::inc() {
	if (!(count == max)) {
		count++;
	}
}

void LimitedCounter::dec() {
	if (!(count == 0)) {
		count--;
	}
}

LimitedCounter::operator int() {
	return count;
}

LimitedCounter::LimitedCounter(int ctr, int maxx)  {
	if (maxx < 0) {
		max = 0;
	}
	else {
		max = maxx;
	}

	if (ctr < 0) {
		count = 0;
	}
	else if (ctr > max) {
		count = max;
	}
	else {
		count = ctr;
	}
}


class OverflowCounter : public Counter {
public:
	void inc();
	void dec();
	operator int();
	OverflowCounter(int ctr = 0, int maxx = 10);
private:
	int count;
	int max;
};

void UseCounter(Counter& ctr, int num);
void UseCounter(Counter& ctr, int num) {
	for (int i = 0; i < num; i++) {
		ctr.inc();
	}

	for (int i = num; i < 0; i++) {
		ctr.dec();
	}
}

void OverflowCounter::inc() {
	count++;
	if (count > max) {
		count = 0;
	}
}

void OverflowCounter::dec() {
	count--;
	if (count < 0) {
		count = max;
	}
}

OverflowCounter::operator int() {
	return count;
}

OverflowCounter::OverflowCounter(int ctr, int limit0) {
	if (limit0 < 0) {
		max = 0;
	}
	else {
		max = limit0;
	}

	if (ctr > max) {
		count = max;
	}

	else if (ctr < 0) {
		count = 0;
	}
    
	else {
		count = ctr;
	}
}


int main(int argc, char** argv) {
	LimitedCounter lc(0, 5);
	OverflowCounter oc(5, 9);

	cout << oc << endl;
	UseCounter(oc, 5);
	cout << oc << endl; // should display zero
	UseCounter(oc, -1);
	cout << oc << endl; // should display 9
	oc.dec();
	cout << oc << endl; // should display 8

	cout << lc << endl;
	lc.inc();
	cout << lc << endl;
	lc.dec();
	cout << lc << endl;
	for(int i = 0; i < 10; ++i) lc.inc();
	cout << lc << endl;
	UseCounter(lc, -9);
	cout << lc << endl;

	return 0;
}
