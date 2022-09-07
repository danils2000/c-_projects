#include <iostream>
#include <vector>
#include <cmath> 
using namespace std;

#define ui64 uint64_t
#define modulo 1000000007

class Exponentiation {
    private:
        ui64 input, intermediateAnswer = 0, answer = 0;
        vector<ui64> numbers;
        vector<ui64> answers;
        void inputNumbers();
        void printAnswers();
        void raisedToPow();
    public:
        Exponentiation(vector<ui64> x);
        void functionsCaller(vector<ui64> x);
};

inline Exponentiation::Exponentiation(vector<ui64> x) {
    numbers = x;
}

inline void Exponentiation::printAnswers() {
    cout << "Output: " << "\n";
    for (ui64 i = 0; i < answers.size(); i++) {
        cout << answers[i] << "\n";
    }
}

void Exponentiation::raisedToPow() {
    for (ui64 i = 0; i < numbers.size(); i += 3) {
        intermediateAnswer = pow(numbers.at(i), numbers.at(i + 1));
        answer = pow(intermediateAnswer, numbers.at(i + 2));

        answers.push_back(answer);
    } 
}

void Exponentiation::inputNumbers() {
    for (ui64 i = 0; i < numbers.size(); i++) {
        cin >> input;
        numbers[i] = input;
    }
}

inline void Exponentiation::functionsCaller(vector<ui64> x) {
    inputNumbers();
    raisedToPow();
    printAnswers();;
}

int main() {
    ui64 lenght = 0;
    cin >> lenght;

    lenght *= 3;

    vector<ui64> numbers(lenght);

    Exponentiation test(numbers);
    test.functionsCaller(numbers);
}
