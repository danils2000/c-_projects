#include <iostream>
#include <cstdlib>
using namespace std;

float mean(int* array, int n);

float mean(int* array, int n) {
	float sum = 0;
	
	for (int i = 0; i < n; i++) {
		sum += array[i];
	}
		sum = sum / n;
		return sum;
}


int main() {
	int input = 0, num = 1;
	int* numbers;

	cout << "Enter how many numbers shoudl randomly generated: ";
	cin >> input;

	numbers = new int[input];

	if (input >= 0) { 
    		for (int i = 0; i < input; i++) {
			numbers[i] = rand() % 100;
        		cout << num << ". ";
			cout << numbers[i] << endl;
        		num++;
		}
		cout << "Avarage:  " << mean(numbers, input) << endl;
		} 
   		else {
        		cout << "Erorr" << endl;
        		return 0;
		}
	delete[] numbers;
}
