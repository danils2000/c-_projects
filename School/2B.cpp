#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> find_field() {
    vector<string> word;
    string input;
    auto pos = 0;
    unsigned j = 0;

    do {
		cout << "Enter a new string :";
		getline(cin, input);
		pos = input.find("stop");
		if (pos == -1) {
			word.push_back(input);
		}
        j++;

	} while (pos == -1);

    return word;
}

int main() {
    vector<string> result = find_field();
    unsigned int leng = 0;
    int pos = 0;
    string word;

    cout << endl;
    cout << "Entred strings:" << endl;

    for (vector<string>::const_iterator i = result.begin(); i != result.end(); ++i) {
        cout << *i << endl;  
    }

     auto it = max_element(result.begin(), result.end(),
                               [](const auto& a, const auto& b) {
                                   return a.size() < b.size();
                               });

    word = *it;

    cout << endl;
    cout << "Longest word is              = " << *it << "[" << word.length() << "]" << endl;
    cout << "Number of elements in vector = " << result.size() << endl;
    cout << "Capacity of vector           = " << result.capacity() << endl;

}
