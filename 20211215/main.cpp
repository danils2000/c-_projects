#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> numbers;

void creation_and_sorting(int max_number, int max_power) {
    for (int i = 2; i <= max_number; i++) {
        for (int j = 2; j <= max_power; j++) {
            int number = pow(i, j);
            numbers.push_back(number);
        }
    }
    sort(numbers.begin(), numbers.end());
    for(auto i: numbers) {
        cout << i << endl;
    }
}

int main() {
    cout << "Test: ";
    creation_and_sorting(5, 100); //test
}
