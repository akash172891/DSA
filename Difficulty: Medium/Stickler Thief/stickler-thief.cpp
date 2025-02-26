//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the maximum money the thief can get.
    
    
    int fxn(int i, vector<int>arr, vector<int>&dp) {
        if(i<0) return 0;
        if(dp[i]!=0) return dp[i];
        
        int take = arr[i] + fxn(i-2,  arr,dp);
        int notake =  fxn(i-1, arr,dp);
        
        return dp[i]=max(take, notake);
    }
    
    
    int findMaxSum(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        
        vector<int>dp(n+1,0);
        dp[0]=0;
        
        for(int i  = 1;i<=n;i++) {
            int take = arr[i-1], notake=0;
            if(i-2 >=0)take = arr[i-1] + dp[i-2];
            if(i-1>=0) notake = dp[i-1];
            dp[i] = max(take, notake);
        }
        
        return dp[n];
    }
};


//{ Driver Code Starts.

int main() {

    // taking total testcases
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

        Solution ob;
        // calling function findMaxSum()
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends