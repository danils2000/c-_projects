#include <iostream>  
#include <math.h>  
#include <iomanip>
using namespace std; 

class CubeDiagonal {
    private:
        double side = 0;
        double diagonal = 0;
    public:
        void sideLenght(double volume);
        void diogonalLenght(double side);
};

void CubeDiagonal::sideLenght(double volume) {
    //by formula side = 3√volume
    side = pow(volume, 1.0 / 3.0);

    return diogonalLenght(side);
}

void CubeDiagonal::diogonalLenght(double side) {
    //by formula diagonal = side*√3 
    diagonal = side * (sqrt(3));

    cout << fixed << setprecision(2) << diagonal << "\n";
}


int main() {
    CubeDiagonal test;
    double volume = 0;

    cin >> volume;

    test.sideLenght(volume);
}
