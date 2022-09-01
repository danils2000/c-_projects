#include <iostream>  
using namespace std;

template<class T> 
class StringMatching {
    private:
        int answer = 0, sizeOfInput = 0, sizeOfPattern = 0;
        T userInput = "", pattern = "";
        void checkIsEmpty();
        void checkSizes();
        int printAnswer(int answer);
        void kmpAlgorithm();
    public:
        StringMatching(T userInput, T pattern);
        void functionCaller();
};

template<class T>
inline StringMatching<T>::StringMatching(T x, T y) {
    userInput = x;
    pattern = y;
}

template<class T>
inline void StringMatching<T>::kmpAlgorithm() {
    int nextShift[sizeOfPattern + 1];

    for (int i = 0; i < sizeOfPattern + 1; i++) {
        nextShift[i] = 0;
    }
 
    for (int i = 1; i < sizeOfPattern; i++) {
        int j = nextShift[i + 1];
 
        while (j > 0 && pattern[j] != pattern[i]) {
            j = nextShift[j];
        }
 
        if (j > 0 || pattern[j] == pattern[i]) {
            nextShift[i + 1] = j + 1;
        }
    }
 
    for (int i = 0, j = 0; i < sizeOfInput; i++) {
        if (userInput[i] == pattern[j]) {
            if (++j == sizeOfPattern) {
                answer++;
            }
        }
        else if (j > 0) {
            j = nextShift[j];
            i--;
        }
    }
}

template<class T>
inline int StringMatching<T>::printAnswer(int answer) {
    cout << "Output: " << "\n" << answer << "\n";
    return 0;
}

template<class T>
inline void StringMatching<T>::checkSizes() {
    sizeOfInput = userInput.length();
    sizeOfPattern = pattern.length();
}

template<class T>
inline void StringMatching<T>::checkIsEmpty() {
    if (userInput.empty() || sizeOfPattern > sizeOfInput || pattern.empty()) {
        cout << "Check your input values" << "\n";
        exit(0);
    } 
    else {
        kmpAlgorithm();
    }
}

template<class T>
inline void StringMatching<T>::functionCaller() {
    checkSizes();
    checkIsEmpty();
    printAnswer(answer);
}

int main() {
    string userInput = "", pattern = "";
    
    cout << "Input:" << "\n";
    cin >> userInput >> pattern;

    StringMatching<string> test(userInput, pattern);
    test.functionCaller();
}
