//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
  
    bool fxn(vector<int> arr, int ind, int k, vector<vector<int>>&dp) {
        
        if(k==0) return true;
        if(ind<0 || k<0) return false;
        if(dp[ind][k]!=-1) return dp[ind][k];
        
        bool take = false, notake =false;
        
        take = fxn(arr, ind-1, k-arr[ind], dp);
        notake = fxn(arr, ind-1, k, dp);
        
        return dp[ind][k]=take||notake;
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(target+1, 0));
        
        for(int i=0;i<=n;i++) {
            dp[i][0]=1;
        }
        
        for(int ind=1;ind<=n;ind++) {
            for(int k=0;k<=target;k++) {
                 bool take = false, notake =false;
                if(k-arr[ind-1] >=0)
                take = dp[ind-1][k-arr[ind-1]];
                
                notake = dp[ind-1][k];
                
                 dp[ind][k]=take||notake;
            }
        }
        
        return dp[n][target];
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
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends