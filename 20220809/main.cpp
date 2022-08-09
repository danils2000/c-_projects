#include <iostream>  
#include <vector>
using namespace std; 

#define ui64 uint64_t

class factory { 
    private:
        int products = 0, number = 0, machines = 0, total = 0;
    public:
        ui64 answer = 0;
        vector<ui64> v1;
        vector<ui64> result;
    

void userInput() {
    cout << "Type amout of machines and products" << "\n";
    cin >> machines >> products;

    return neededTime();
}

void neededTime() {
    for (int i = 0; i < machines; i++) {
        cin >> number;
        v1.push_back(number);
    }
    return calculation();
}

void calculation() {
    for (auto x : v1) {
        int add = x;
        products++;
        while (add < products) {
            add += x;
            products++;
            if (add > products) {
                add -= x;
            }
            cout << add << " HERE " << endl;
            break;
        }
        cout << endl;
        result.push_back(x);
    }
    cout << total << "\n";
    for (auto i : result) {        
        cout << i << "\n";
    }
}
};

int main() {
    factory a;
    a.userInput();
}
