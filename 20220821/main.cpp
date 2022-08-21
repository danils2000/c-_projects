#include <iostream>  
#include <vector>
#define module 1000000007
using namespace std; 

class Dice {
    private:
        int answer = 0, size = 0;
        void combintations(vector<int>& dp);
        int result(vector<int>& dp, int sum);
    public:
        void caller(vector<int>& dp, int sum);
};

void Dice::combintations(vector<int>& dp) {
    dp[0] = 1;

    for (int i = 1; i <= dp.size(); i++) {
        for (int j = 1; j <= 6 && i - j >= 0; j++) {
            dp[i] = (dp[i] + dp[i - j]) % module;
        }
    }
}

inline int Dice::result(vector<int>& dp, int sum) {
    answer = dp[sum];
    return answer;   
}

inline void Dice::caller(vector<int>& dp, int sum) {
    combintations(dp);
    cout << result(dp, sum) << "\n";
}

int main() {
    Dice test;
    int sum = 0;

    cin >> sum;

    vector<int> dp(sum + 1);
    test.caller(dp, sum);
}
