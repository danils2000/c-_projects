#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std; 

class MagicSquare {
    public: 
        void userInput(int a, int b);
    private:
        int sum = 0;
        bool isEqual = true;
        vector<int> total;
        void check(vector<int>& total);
};

void MagicSquare::userInput(int a, int b) {
    //input numbers
    int square[a][b];
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> square[i][j];
            sum += square[i][j];
        }
        total.push_back(sum);
        sum = 0;
    }

    check(total);
}

void MagicSquare::check (vector<int>& total) {
    if(equal(total.begin()+ 1, total.end(), total.begin())) {
        isEqual = true;
    }
    else {
        isEqual = false;
    }

    cout << boolalpha <<isEqual << "\n";
}


int main() {
    MagicSquare test;
    int rowsAndColoums = 0;

    cout << "How many rows and Coloums you need: ";
    cin >> rowsAndColoums;

    test.userInput(rowsAndColoums, rowsAndColoums);
}
