#include <iostream>  
#include <vector>
#include <math.h>
#define module 1000000007
#define ui64 uint64_t
using namespace std;

class Exponentiation {
    private:
        int number = 0, number2 = 0;
        ui64 result = 0;
        void readValues(vector<pair<int, int>>& numbers);
        void showAnswers(vector<pair<int, int>>& numbers);
        ui64 array[];
    public:
        void caller(vector<pair<int, int>>& numbers);
};

void Exponentiation::showAnswers(vector<pair<int, int>>& numbers){
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i].first << "^" << numbers[i].second << " = ";

        result = pow(numbers[i].first, numbers[i].second);
        result = result % module;
        cout << result << "\n";
    }
}

void Exponentiation::readValues(vector<pair<int, int>>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        cin >> number >> number2;
        numbers[i] = make_pair(number, number2);
    }
}

inline void Exponentiation::caller(vector<pair<int, int>>& numbers) {
    readValues(numbers);
    showAnswers(numbers);
}


int main() {
    Exponentiation test;
    int amout = 0;

    cin >> amout;

    vector<pair<int, int>> numbers(amout);

    test.caller(numbers);
}
