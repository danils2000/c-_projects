/*
Convert numbers to words up to 100
*/

#define pass (void)0

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private:
        int integer = 0;
        vector<string> ones = {"zero", 
        "one", 
        "two", 
        "three", 
        "four", 
        "five", 
        "six", 
        "seven", 
        "eight", 
        "nine" , 
        "ten", 
        "eleven", 
        "twelve",
        "thirthy",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
    };
    vector<string> tens = { "", "", 
        "twenty", 
        "thirty", 
        "fourthy", 
        "fifty", 
        "sixty", 
        "seventy", 
        "eighty", 
        "ninety"};
    string hungred = "hungred";  

public:
    int lenght(int num) {
        if (num < 20) {
            return until_twenty(num);
        }
        else if (num >= 20 && num < 100) {
            return until_hungred(num);
        }
    }

private: 
    int until_twenty(int num) {
        if (num < 20) {
            do {
                cout << ones[integer] << endl;
                integer++;
            } while (integer != num + 1);
        }
    }

    int until_hungred(int num) {
        until_twenty(19);
        if (num < 100) {
           integer = num / 10;
           for(int i = 2; i <= integer; i++) { 
                for (int j = 0; j < 10; j++) {
                    if (j == 0) {
                        cout << tens[i] << endl;
                    } 
                    else {
                        cout << tens[i] + " " + ones[j] << endl;
                    }
                    if (j == 10) {
                        j == 0;
                    }
                }
            }
        }
    }
};

int main() {
    cout << "First: " << endl;
    Solution().lenght(99);
    cout << "Second: " << endl;
    Solution().lenght(18);
}
