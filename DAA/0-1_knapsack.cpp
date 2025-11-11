#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> profit, vector<int> weight, int capacity, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weight[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(
                    dp[i - 1][w],
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]]
                );
            }
        }
    }
    cout<<"Items included in knapsack are:";

    int w = capacity;
    for(int i=n;i>0 && w>0;i--){
        if(dp[i][w]!=dp[i-1][w]){
            cout<<i<<" ";
            w = w - weight[i-1];
        }
    }

    return dp[n][capacity];
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> profit(n), weight(n);
    cout << "Enter profit and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> profit[i] >> weight[i];
    }

    int capacity;
    cout << "Enter maximum weight of knapsack: ";
    cin >> capacity;

    cout << "\nMaximum profit: " << knapsack(profit, weight, capacity, n);
}