//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int ways(vector<int> arr, int ind , int sum, vector<vector<int>> &dp) {
      
      if(sum == 0) return 1;
      if(sum < 0 || ind < 0) return 0;
    //   if(ind == 0) return arr[ind]==sum;
    
    if(dp[ind][sum]!=-1) return dp[ind][sum];
       
      int take =0, notake =0;
      
      if(sum >= arr[ind]) {
          take = ways(arr, ind, sum-arr[ind], dp);
      }
      notake = ways(arr, ind-1, sum, dp);
      return dp[ind][sum]=take + notake;
      
  }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return ways(coins, n-1, sum, dp);
        
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends