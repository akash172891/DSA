//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fxn(vector<int>& arr, int ind, int prev, vector<vector<int>>&dp) {
        if(ind>=arr.size()) return 0;
        int take = 0, notake = 0;
        if(dp[ind+1][prev+1]!=-1) return dp[ind+1][prev+1];
        if(prev==-1 ||  arr[ind]>arr[prev]) {
            take = 1+fxn(arr, ind+1, ind, dp);
           
        }
         notake = fxn(arr, ind+1, prev, dp);
         
         return dp[ind+1][prev+1]= max(take, notake);
    }
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return fxn(arr, 0, -1, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends