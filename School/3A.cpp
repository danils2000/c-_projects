#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    vector<double> num;
    double number;
    auto pos = 0;

    cout << "Enter numbers:" << endl;
    do {
        cin >> number;
        num.push_back(number);

    } while (number > 0);
    //delete last element
    num.pop_back();


    cout << endl << "Numbers since lowest:" << endl;
    sort(num.begin(), num.end());
        for (const auto &i: num) {
            cout << i << ' '<<endl;
   }
}
