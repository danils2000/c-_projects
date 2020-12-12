#include <iostream>
#include <vector>
using namespace std;

class Counter; 
class Observer {
public:
	virtual void HandleLimitReached(Counter *ctr) = 0;
};

class Counter {
public:
	virtual void inc() = 0;
	virtual void dec() = 0;
	virtual operator int() = 0;
	virtual void SetObserver(Observer* observer) = 0;
	virtual ~Counter() {};
};


class OverflowCounter : public Counter {
public:
	OverflowCounter(int count = 0, int maxx = 10);
	virtual void inc();
	virtual void dec();
	virtual operator int();
	virtual void SetObserver(Observer* observer);
private:
	int counter;
	int limit;
	void Notify();
	vector<Observer*> observers;
};


class LimitCounter : public Counter {
public:
	LimitCounter(int count = 0, int maxx = 10);
	virtual void inc();
	virtual void dec();
	virtual operator int();
	virtual void SetObserver(Observer* observer);
private:
	void Notify();
	int counter;
	int limit;
	vector<Observer*> observers;
};

class CounterUser : public Observer {
public:
	CounterUser() { } 
	virtual void HandleLimitReached(Counter* ctr) {
		cout << "Limit of " << *ctr << " is reached." << endl;
	}
};

void UseCounter(Counter& ctr, int num);

int main(int argc, char** argv) {
	OverflowCounter oc(5, 10);
	LimitCounter lc(5, 10);
	CounterUser observerOne;
	CounterUser observerTwo;
	CounterUser observerThree;

	oc.SetObserver(&observerOne);
	lc.SetObserver(&observerTwo);

	oc.SetObserver(&observerThree);
	lc.SetObserver(&observerThree);

	cout << "First test (4): " << endl;
	UseCounter(oc, 20); 
	cout << "Second test (8): " << endl;
	UseCounter(lc, 9);

	return 0;
}

void UseCounter(Counter& ctr, int num) {
	for (int i = 0; i < num; i++) {
		ctr.inc();
	}

	for (int i = num; i < 0; i++) {
		ctr.dec();
	}
}

OverflowCounter::OverflowCounter(int count, int maxx) {
	if (maxx < 0) {
		limit = 0;
	}
	else {
		limit = maxx;
	}

	if (count > limit) {
		counter = limit;
	}
	else if (count < 0) {
		counter = 0;
	}
	else {
		counter = count;
	}
}

void OverflowCounter::inc() {
	if (counter < limit) {
		counter++;
	}
	else {
		Notify();
		counter = 0;
	}
}

void OverflowCounter::dec() {
	if (counter > 0) {
		counter--;
	}
	else {
		Notify();
		counter = limit;
	}
}

OverflowCounter::operator int() {
	return counter;
}

void OverflowCounter::SetObserver(Observer* observer) {
	observers.push_back(observer);
}

void OverflowCounter::Notify() {
	for (int i = 0; i < observers.size(); i++) {
		observers[i]->HandleLimitReached(this);
	}
}

LimitCounter::LimitCounter(int count, int maxx) {
	if (maxx < 0) {
		limit = 0;
	}
	else {
		limit = maxx;
	}
	
	if (count < 0) {
		counter = 0;
	}
	else if (count > limit) {
		counter = limit;
	}
	else {
		counter = count;
	}
}

void LimitCounter::inc() {
	if (counter < limit) {
		counter++;
	}
	else {
		Notify();
	}
}

void LimitCounter::dec() {
	if (counter < 0) {
		counter--;
	}
	else {
		Notify();
	}
}

LimitCounter::operator int() {
	return counter;
}

void LimitCounter::SetObserver(Observer* observer) {
	observers.push_back(observer);
}

void LimitCounter::Notify() {
	for (int i = 0; i < observers.size(); i++) {
		observers[i]->HandleLimitReached(this);
	}
}