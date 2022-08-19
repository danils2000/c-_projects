#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std;

class Calculation {
    private:
        vector<int> answer;
        int value = 0;
        void show(vector<int>& numbers);
        void readValues(vector<int>& answer);
        void findSum(vector<int>& numbers, int sum); 
    public:
        void functionsCaller(vector<int>& numbers, int sum);
};

void Calculation::show(vector<int>& answer) {
    if (answer.empty()) {
        cout << "IMPOSSIBLE" << "\n";
    } 
    else {
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << " ";
        }
    }
}

void Calculation::readValues(vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        cin >> value;
        numbers[i] = value;
    }
}

void Calculation::findSum(vector<int>& numbers, int sum) {
    for (int i = 0; i < (numbers.size() - 1); i++) {
        for (int j = 0; j < numbers.size(); j++) {
            if (numbers[i] + numbers[j] == sum) {
                answer.insert(answer.end(), {i + 1, j + 1});
            }
        }
    }
}

void Calculation::functionsCaller(vector<int>& numbers, int sum) {
    readValues(numbers);
    findSum(numbers, sum);
    show(answer);
}

int main() {
    Calculation test1;
    int lenght = 0, sum = 0;
    cin >> lenght >> sum;
    vector<int> numbers(lenght);
    
    test1.functionsCaller(numbers, sum);
}
