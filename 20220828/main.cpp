#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std;

template<class T> 
class countingDivisors {
    private:
        T number = 0, amoutOfDivisors = 0;
        vector<T> answers;
        vector<T> givenNumbers;
        void readValues(T amoutOfNumbers);
        void foundDivisors(T amoutOfNumbers);
        void printAnswer();
    public:
        void functionsCaller(T amoutOfNumbers);
};

template<class T>
inline void countingDivisors<T>::printAnswer() {
    for (T i = 0; i < answers.size(); i++) {
        cout << answers[i] << ", ";
    }
    cout << "\n";
}

template<class T>
void countingDivisors<T>::foundDivisors(T amoutOfNumbers) {
    vector<T> answers(amoutOfNumbers);
    for (T i = 0; i < givenNumbers.size(); i++) {
        amoutOfDivisors = 0;
        for (T j = 1; j <= givenNumbers[i]; j++) {
            if (givenNumbers[i] % j == 0) {
                amoutOfDivisors++;
            }
        }
        answers[i] = amoutOfDivisors;
    }
    this -> answers = answers;
}

template<class T>
void countingDivisors<T>::readValues(T amoutOfNumbers) {
    vector<T> givenNumbers(amoutOfNumbers);
    for (T i = 0; i < givenNumbers.size(); i++) {
        cin >> number;
        givenNumbers[i] = number;
    }
    this -> givenNumbers = givenNumbers;
}

template<class T>
inline void countingDivisors<T>::functionsCaller(T amoutOfNumbers) {
    readValues(amoutOfNumbers);
    foundDivisors(amoutOfNumbers);
    printAnswer();
}

int main() {
    int amoutOfNumbers = 0;
    cin >> amoutOfNumbers;

    countingDivisors<int> test;

    test.functionsCaller(amoutOfNumbers);
}
