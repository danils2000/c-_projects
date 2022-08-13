
class Salary {
public:
    Salary(int);
    ~Salary();
    void calculation();
private:
    int days;
    int salary = 0;
    void print();
};

Salary::Salary(int a) {
    this -> days = a;
}

Salary::~Salary() {

}

void Salary::calculation() {
    for (int i = 0; i < days; i++) {
        if (i == 0) {
            salary = 1;
        }
        else {
            salary = salary * 2 + 1;
        }
    }
    return print();
}

void Salary::print() {
    cout << "Salary is: " << salary << endl;
}

int main() {
    Salary test1(1);
    Salary test2(2);
    Salary test3(3);
    Salary test4(4);

    test1.calculation();
    test2.calculation();
    test3.calculation();
    test4.calculation();
};
