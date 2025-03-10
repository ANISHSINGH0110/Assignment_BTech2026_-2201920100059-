#include <iostream>
#include<vector>
using namespace std;

const int MOD = 1e9 + 7;

int diceWays(int n) {
    if (n == 0) 
     return 1;  
    if (n < 0) 
     return 0;   

    int ways = 0;
    for (int i = 1; i <= 6; i++) {  
        ways = (ways + diceWays(n - i)) % MOD;
    }

    return ways;
}
int diceWaysMemo(int n, vector<int>& dp) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    if (dp[n] != -1) return dp[n];  // Use cached value

    int ways = 0;
    for (int i = 1; i <= 6; i++) {
        ways = (ways + diceWaysMemo(n - i, dp)) % MOD;
    }

    return dp[n] = ways;
}
int diceWaysTab(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;  // Base case

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter the value of n :" << endl;
    cin >> n;

    //vector<int> dp(n + 1, -1); 

    // cout << "the number of ways to construct sum n by throwing a dice one or more times : " << diceWays(n) << endl;

    // cout << "the number of ways to construct sum n by throwing a dice one or more times : " << diceWaysMemo(n,dp) << endl;
    
    cout << "the number of ways to construct sum n by throwing a dice one or more times : " << diceWaysTab(n) << endl;


    return 0;
}
