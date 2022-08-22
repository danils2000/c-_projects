#include <iostream>  
#include <vector>
#include <math.h>
#define module 1000000007
#define ui64 uint64_t
#define MAX 128
using namespace std;

class Exponentiation {
    private:
        int number = 0, number2 = 0;
        ui64 result = 0;
        void readValues(vector<pair<int, int>>& numbers);
        void calculation(vector<pair<int, int>>& numbers);
        void showAnswers(int array[]);
        int array[MAX] = {};
    public:
        void caller(vector<pair<int, int>>& numbers);
};

void Exponentiation::showAnswers(int array[]) {
    for (int i = 0; i < sizeof(*array) - 1; i++) {
        cout << array[i] << ", ";
    }
}

void Exponentiation::calculation(vector<pair<int, int>>& numbers){
    for (int i = 0; i < numbers.size(); i++) {
        result = pow(numbers[i].first, numbers[i].second);
        array[i] = result;
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
    calculation(numbers);
    showAnswers(array);
}


int main() {
    Exponentiation test;
    int amout = 0;

    cin >> amout;

    vector<pair<int, int>> numbers(amout);

    test.caller(numbers);
}
