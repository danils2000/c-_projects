#include <iostream>  
#include <vector>
#include <algorithm>  
using namespace std;

class Password {
    private:
        int a = 0;
        vector<bool> checks{false, false, false, false, true};
    public:
        void checking(string password);
        void lenght(string password);
        void result();
};

void Password::checking(string password) {
    //lenght
    if (password.size() <= 24 && password.size() > 5) {
        checks[0] = true;
    }
    for (int i = 0; i < password.size(); i++) {
        //uppercase
        if(isupper(password[i])) {
            checks[1] = true;
        }
        //lower case
        else if(islower(password[i])) {
            checks[2] = true;
        }
        //numbers
        else if(isdigit(password[i])) {
            checks[3] = true;
        }
    }
    return lenght(password);
}

void Password::lenght(string password) {
     for (int i = 0; i < password.size(); i++) {
        if ((password[i] == password[i + 1] && password[i + 1] == password[i + 2])) {
            checks[4] = false;
            break;
        }
    }
    result();
}

void Password::result() {
    if (all_of(checks.begin(), checks.end(), [](bool v) { return v; })) {
        cout << "all are true";
    }
    else {
        cout << "Something is wrong";
    }
}

int main() {
    Password test1;
    string password;

    cin >> password;

    test1.checking(password);
}
