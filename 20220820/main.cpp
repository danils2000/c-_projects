#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std;

class Ferris {
    private:
        int weight = 0, gondolas = 0, twoChilds = 0;
        void readValues(vector<int>& answer);
        void sorting(vector<int>& numbers);
        void findGondolas(vector<int>& numbers, int sum); 
        int calculating(vector<int>& numbers);
    public:
        void functionsCaller(vector<int>& numbers, int sum);
};

void Ferris::sorting(vector<int>& numbers) {
    sort(numbers.begin(), numbers.end());
}

void Ferris::readValues(vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        cin >> weight;
        numbers[i] = weight;
    }
}

void Ferris::findGondolas(vector<int>& numbers, int maxWeight) {
    int j = numbers.size() - 1;
    while (int i = 0 < j) {
        if(numbers[i] + numbers[j] >= maxWeight) {
            j--;
        }
        else {
            numbers[i] = numbers[j] = 0;
            i++;
            j--;
        }
    }
}

int Ferris::calculating(vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] > 0 ) {
            gondolas++;
        } 
        else {
            twoChilds++;
        }
    }
    gondolas += (twoChilds / 2);

    return gondolas;
}

void Ferris::functionsCaller(vector<int>& numbers, int maxWeight) {
    readValues(numbers);
    sorting(numbers);
    findGondolas(numbers, maxWeight);
    cout << calculating(numbers);
}

int main() {
    Ferris test1;
    int childrens = 0, maxWeight = 0;
    cin >> childrens >> maxWeight;
    vector<int> numbers(childrens);
    
    test1.functionsCaller(numbers, maxWeight);
}
