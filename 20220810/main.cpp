#include <iostream>
using namespace std;

void calculation(string &DNA);

void getDNA() {
    string DNA;
    cin >> DNA;

    calculation(DNA);
}

void calculation(string &DNA) {
    int max = 0, amout = 0;
    int size = DNA.length();

    for (int i = 0; i < size; i++) {
        amout = 0;
        for (int j = 0; j < size; j++) {
            if (DNA[j] == DNA[i]) {
                amout++;
                if (amout > max) {
                    max = amout;
                }
            }
            else {
                amout = 0;
            }
        }
    }
    cout << max << "\n";
}

int main() {
    getDNA();
}
