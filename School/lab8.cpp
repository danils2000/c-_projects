#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	Person(const char* name = "nobody");
	virtual ~Person() = default;
	virtual void identity() const;
	virtual void interrogate();
private:
	string name;
};

Person::Person(const char* name0) : name(name0) {
}

void Person::identity() const {
	cout << "My name is: " << name << endl;
}

void Person::interrogate() { 
}


class Spy : public Person {
public:
	Spy(const char* name = "nobody", const char* alias = "nobody", int resistance = 0);
	void set_identity(string alias);
	virtual void identity() const override;
	virtual void interrogate() override;
private:
	string alias;
	int resistance;
};

Spy::Spy(const char* name0, const char* alias0, int resistance0) : Person(name0), resistance(resistance0), alias(alias0) {

 }

void Spy::set_identity(std::string alias) {
	this->alias = alias;
	Person::identity(); // for name
}


void Spy::identity() const {
	if (resistance <= 0) { 
		cout << "My alias is : " << alias << endl;
	}
	if (resistance > 0) { 
		cout << "My name is : " << alias << endl;
	}
}

void Spy::interrogate() {
	resistance--;
	if (resistance <= 0) {
		Person::identity();
	}
}



int main(int argc, char** argv) {

	Person agent("James Bond");
	Spy spy("Emilio Largo", "William Johnson", 3);
	Spy spy2("Ernst Blofield", "John Keats", 5);

	cout << endl << "Nice to meet you. ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		cout << "Who are you?" << endl;
		spy.interrogate();
		spy.identity();
	}
	spy.set_identity("Bill Munny");
	spy.identity();

	cout << endl << "Nice to meet you. ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		cout << "Who are you?" << endl;
		spy2.interrogate();
		spy2.identity();
	}

	return 0;
}