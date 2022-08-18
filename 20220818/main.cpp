#include <iostream>  
#include <vector>
#include <algorithm>  
using namespace std;

class Password {
    private:
        vector<bool> checks{false, false, false, false, true};
        void digitElement(string password);
        void lenght(string password);
        void upperLowerCases(string password);
        void repeatedCharacters(string password);
    public:
        void result(string password);
};

void Password::lenght(string password) {
    if (password.size() <= 24 && password.size() > 5) {
        checks[0] = true;
    }
}

void Password::upperLowerCases(string password) {
    for (int i = 0; i < password.size(); i++) {
        if(isupper(password[i])) {
            checks[1] = true;
        }
        else if(islower(password[i])) {
            checks[2] = true;
        }
    }
}

void Password::digitElement(string password) { 
    for (int i = 0; i < password.size(); i++) {
        if(isdigit(password[i])) {
            checks[3] = true;
        }
    }
}

void Password::repeatedCharacters(string password) {
     for (int i = 0; i < password.size(); i++) {
        if ((password[i] == password[i + 1] && password[i + 1] == password[i + 2])) {
            checks[4] = false;
            break;
        }
    }
}

void Password::result(string password) {
    lenght(password);
    upperLowerCases(password);
    digitElement(password);
    repeatedCharacters(password);

    if (all_of(checks.begin(), checks.end(), [](bool v) { return v; })) {
        cout << "All are true, your password is match" << "\n";
    } 
    else {
        cout << "Something is wrong. Check password instruction one more time" << "\n";
    }
}

int main() {
    Password test1;
    string password;

    cin >> password;

    test1.result(password);
}
