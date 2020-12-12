#include <iostream>
#include <vector>
using namespace std;

class Counter; 
class Observer {
public:
	virtual void HandleLimitReached() = 0;
};

class Counter {
    friend ostream& operator<<(ostream& out, const Counter& ct);
public:
	Counter(int count = 0);
	virtual void inc() = 0;
	virtual void dec() = 0;
	virtual operator int() = 0;
	virtual ~Counter() {};
	int count;
};


class OverflowCounter : public Counter {
	friend ostream& operator<<(ostream& out, const OverflowCounter& oct);
public:
	OverflowCounter(int count = 0, int maxx = 0); 
	void inc();
	void dec();
	operator int();
    void SetObserver(Observer* ofc); 
	virtual ~OverflowCounter() {};
private:
	int maxx;
	void Notify();
	Observer *observers;
};

class LimitCounter : public Observer {
public:
	LimitCounter(int max = 0);
    void HandleLimitReached(); 
	void IncrementBy(int num);
private:
	OverflowCounter ofc;
};

    LimitCounter::LimitCounter(int max){ // Initialization
	ofc = OverflowCounter(0, max);
	ofc.SetObserver(this);
}


Counter::Counter(int count0): count(count0) { // Initialization

}

OverflowCounter::OverflowCounter(int count0, int max)	:maxx(max) { // Initialization
count = (count0 != maxx) ? (count0 < max && 0 <count0) ? count0 : max : 0;

}

void OverflowCounter::inc() {
	if (count < maxx) {
		count++;
	}
    else {
		count = 0;
        Notify();
	}
}

    void OverflowCounter::Notify() {
	observers->HandleLimitReached();
}

void LimitCounter::HandleLimitReached() {
	cout << "Limit has been reached" << endl;
}

void OverflowCounter::SetObserver(Observer* ob) {
	observers = ob;
}

void OverflowCounter::dec() {

	if (count > 0) {
		count--;
	}
	else {
	count = maxx;
	}
}

OverflowCounter::operator int() {
	return count;
}

ostream& operator<<(ostream& out, const Counter&ct) {
	out << ct.count; 
	return out;
}

ostream& operator<<(ostream& out, const OverflowCounter& oct) {
	out << oct.count; // 
    return out;
}

void LimitCounter::IncrementBy(int num) {
	int c = (num < 0) ? num:0;
	int ct = 0;
	for (c; c < num; c++)
	{
		ofc.inc();
	}
}

int main() {
	LimitCounter cu(5);
	cu.IncrementBy(12); //OUTPUT: two times "Limit has been reached"
	LimitCounter cu2(9);
	cu2.IncrementBy(9);
	cout << "Just passing time" << endl;
	cu2.IncrementBy(1); //OUTPUT: "Limit has been reached"

}
