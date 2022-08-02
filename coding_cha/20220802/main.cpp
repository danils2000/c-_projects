#include <iostream>
using namespace std;

int main() {
    //variabels
    long input;

    //calculation
    cin >> input;
    
    if (input > 0) {
        cout << input << " ";
        while (input > 1) {
            if (input % 2 == 0) {
                input = input / 2;
                cout << input << " ";
            }
            else if (input % 2 != 0) {
                input = input * 3 + 1;
                cout << input << " ";
            }
        }
    }
    else {
        return 0;
    }
}

