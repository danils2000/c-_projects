#include <iostream>  
using namespace std; 

class Box {
    private:
        int size = 0;
        void printingBox();
    public:
        Box(int x);
        void functionCaller();
};

inline Box::Box(int x) {
    size = x;
}

void Box::printingBox() {
    for (int i = 0; i < size; i++) {
        cout << "\n";
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == size - 1) {
                cout << "#";
            } 
            else {
                if (j == 0 || j == size -1) {
                    cout << "#";
                }
                else {
                    cout << " ";
                }
            }
        }
    }
}

inline void Box::functionCaller() {
    printingBox();
}

int main() {
    int size = 0;
    cin >> size;

    Box test(size);
    test.functionCaller();
}
