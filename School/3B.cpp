#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backwards(vector<string>& vect);
void backwards(vector<string> &vect) {
	for (auto &element : vect) {
		reverse(element.begin(), element.end());
	}
	sort(vect.rbegin(), vect.rend());
}


int main() {
    vector<string> word;
    string input;
    auto pos = 0;
    int i = 1;

    cout << "Enter a new string" << endl;
    do {
        cout << i <<": ";
	getline(cin, input);
        i++;
	pos = input.find("stop");
		if (pos == -1) {
			word.push_back(input);
		}

	} while (pos == -1);

	cout << endl;
   	cout << "Befor backwards:" << endl;
	for (auto elements : word) {
		cout << elements << endl;
	}

	backwards(word);
	cout << endl;
        cout << "After backwards:" << endl;  
	for (auto element : word) {
		cout << element << endl;
	}
	return 0;
}
