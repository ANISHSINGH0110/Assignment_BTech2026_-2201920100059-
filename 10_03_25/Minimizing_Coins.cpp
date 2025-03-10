#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = 1e9;

int minCoinsRec(vector<int>& coins, int x) {
    if (x == 0) 
     return 0;  
    if (x < 0) 
     return INF; 

    int minCoins = INF;
    for (int coin : coins) {
        minCoins = min(minCoins, minCoinsRec(coins, x - coin) + 1);
    }

    return minCoins;
}
int minCoinsMemo(int x, vector<int>& coins, vector<int>& dp) {
    if (x == 0) 
     return 0;
    if (x < 0) 
     return INF;
    if (dp[x] != -1) 
     return dp[x];

    int minCoins = INF;
    for (int coin : coins) {
        minCoins = min(minCoins, minCoinsMemo(x - coin, coins, dp) + 1);
    }

    return dp[x] = minCoins;
}
int minCoinsTab(int n, int x, vector<int>& coins) {
    vector<int> dp(x + 1, INF);
    dp[0] = 0;  

    for (int i = 1; i <= x; i++) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return (dp[x] == INF ? -1 : dp[x]);
}
int main() {
    int n = 3;
    int x = 11;
    vector<int> coins = {1,5,7};

    // int result = minCoinsRec(coins, x);
    // cout << "the minimum number of coins : " << (result >= INF ? -1 : result) << endl;

    vector<int> dp(x + 1, -1);
    //int result = minCoinsMemo(x, coins, dp);

    int result = minCoinsTab(n,x,coins);


    cout << "the minimum number of coins :" << (result >= INF ? -1 : result) << endl;

    return 0;
}
