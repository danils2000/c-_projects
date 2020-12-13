#include <iostream>
#include <string>
#include <algorithm>   // sort 
#include <vector>  // vector
#include <iterator>  
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
using namespace std;

class UniqueRng {
public:
	UniqueRng(unsigned int range = 0, unsigned int num = 0);
	int operator()();
private:
	unsigned int lower;
	unsigned int upper;
};

void test_generator(UniqueRng ur, int count);

int main() {
	srand((unsigned int)time(NULL));
	UniqueRng randGen1(5, 13);
	cout << "Generating numbers:" << endl;
	test_generator(randGen1, 6);
	cout << "End of generator" << endl;
	cout << "Generating numbers:" << endl;
	test_generator(randGen1, 9);
	cout << "End of generator" << endl;
	cout << "Generating numbers:" << endl;
	test_generator(randGen1, 13);
	cout << "End of generator" << endl;
	
	UniqueRng randGen2(1, 35);
	cout << "Generating numbers:" << endl;
	test_generator(randGen2, 7);
	cout << "End of generator" << endl;
	cout << "Generating numbers:" << endl;
	test_generator(randGen2, 7);
	cout << "End of generator" << endl;
	cout << "Generating numbers:" << endl;
	test_generator(randGen2, 7);
	cout << "End of generator" << endl;
	cout << "Generating numbers:" << endl;
	test_generator(randGen2, 70);
	cout << "End of generator" << endl;
	return 0;
}

UniqueRng::UniqueRng(unsigned int lower0, unsigned int upper0) : lower(lower0), upper(upper0) {
	srand((unsigned int)time(NULL));
}

int UniqueRng::operator()() {

	unsigned int number;
	
	do {
		number = rand() % upper + 1;
	} while (number<lower); // validate lower 
	return number;
}

void test_generator(UniqueRng ur, int count) {
	vector<unsigned int> uniqueNum; // store the num
	int actual_num = 0;
	unsigned int num;
	
	for (int i = 0; i < count; i++) {
		num = ur.operator()();
		if (find(uniqueNum.begin(), uniqueNum.end(), num) == uniqueNum.end()) { // check if the num already exist
			uniqueNum.push_back(num);
			actual_num++;
		}
	}

	if (actual_num != count) {
		cout << "Exception: Unable to produce unique random number" << endl;
		cout << "Tried to generate "<<count << " random numbers.Got only "<< actual_num << endl;
	}

	for (auto n : uniqueNum) {
		cout << n << endl;
	}
	uniqueNum.clear();
}
