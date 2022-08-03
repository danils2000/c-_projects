#include <iostream>  
using namespace std; 

class Cipher {
    private:
        string result = "";
    public:
        void encryption(string sentence, int factor);
};

void Cipher::encryption(string sentence, int factor) {
    for (int i = 0; i < sentence.length(); i++) {
        //uppercase
        if (isupper(sentence[i])) {
            result += char(int(sentence[i] + factor - 65) % 26 + 65);
        }
        //lowercase
        else { 
        result += char(int(sentence[i] + factor - 97) % 26 + 97);
        }
    }
    cout << result << "\n";
}

int main() {
    Cipher test;
    string word;
    int rotationFactor = 0;
    
    cout << "Word of sentences that should be encrypted: ";
    cin >> word;
    cout << "Rotation factor: ";
    cin >> rotationFactor;

    test.encryption(word, rotationFactor);
}
