#include <iostream>  
#include <vector>
#include <algorithm> 
using namespace std; 

class Triangle {
    private:
        int sum = 0, index = 0, max = 0;
        vector<int> path;
        void result();
    public:
        void calculaction(vector<vector<int>> numbers);
};

void Triangle::calculaction(vector<vector<int>> numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        max = 0;
        if (i <= 1) {
            for (int j = 0; j < numbers[i].size(); j++) {
                    auto it = minmax_element(numbers[j].begin(), numbers[j].end());
                    max = *it.second;
                    index = distance(numbers[j].begin(), it.second);
            }
        }
        else {
            if(numbers[i][index] > numbers[i][index+1]) {
                max = numbers[i][index];
            }
            else {
                index++;
                max = numbers[i][index];    
            }
        }
        path.push_back(max);
    }
    return result();
} 

void Triangle::result() {
    for (const auto &i: path) {
        cout << i << " + ";
        sum += i;
    }
    cout << "= " << sum;

}

int main() {
    Triangle test;
    Triangle test2;

    test.calculaction({{7}, {19, 11}, {12, 7, 9}, {10, 83, 5, 47}, {1, 2, 3, 4, 5}});
    cout << "\n";
    test2.calculaction({{3}, {7, 4}, {2, 4, 6}, {8, 5, 9, 3}});
};

