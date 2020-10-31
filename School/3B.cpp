#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> word;
    string input;
    auto pos = 0;
    unsigned j = 0;
    string wo;

    do {
		cout << "Enter a new string :";
		getline(cin, input);
		pos = input.find("stop");
		if (pos == -1) {
			word.push_back(input);
		}

	} while (pos == -1);

    cout << endl;
    cout << "Befor backwards:" << endl;
        for (vector<string>::const_iterator i = word.begin(); i != word.end(); ++i) {
             cout << *i << endl;  
        }

    cout << endl;
    cout << "After backwards:" << endl;  

    reverse(word.begin(),word.end());
     for (vector<string>::const_iterator i = word.begin(); i != word.end(); ++i) {
             cout << *i << endl;  
        }

}
