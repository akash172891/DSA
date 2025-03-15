//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   vector<vector<int>> dp;

    int fn(vector<int> &coins, int sum, int i) {
        if (sum == 0) return 0;
        if (i >= coins.size()) return 1e5;
        if (dp[i][sum] != -1) return dp[i][sum];

        int ans = 1e5;
        ans = min(ans, fn(coins, sum, i + 1)); // Skip the current coin
        if (coins[i] <= sum) ans = min(ans, fn(coins, sum - coins[i], i) + 1); // Take the coin

        return dp[i][sum] = ans;
    }

    int minCoins(vector<int> &coins, int sum) {
        dp.resize(coins.size(), vector<int>(sum + 1, -1)); // Fix dp resizing
        int ans = fn(coins, sum, 0);
        return ans == 1e5 ? -1 : ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends