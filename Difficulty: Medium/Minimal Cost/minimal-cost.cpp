//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fxn(vector<int> arr , int k, int n,vector<int>&dp) {
        if(n==0)return 0;
        if(dp[n]!=0)return dp[n];
        int val = abs(arr[n]-arr[n-1]) + fxn(arr,k,n-1,dp);
        for(int i=1;i<k;i++){
            int val2 = INT_MAX;
            if(n-i-1>=0) val2 = abs(arr[n]-arr[n-1-i]) + fxn(arr,k,n-1-i,dp);
            val = min(val, val2);
        }
        return dp[n]=val;
        
    }
    int minimizeCost(int k, vector<int>& height) {
     int n=height.size();
     vector<int>dp(n+1,0);
      dp[0] = 0;
        if(n>=1) dp[1]=0;
        if(n>=2) dp[2] = abs(height[1]-height[0]);
        
        for(int ind=3;ind<=n;ind++) {
            
            
            int kjump = INT_MAX;
            for(int j=1;j<=k;j++) {
                if(ind-1-j >=0)
                kjump = min(kjump, dp[ind-j]+abs(height[ind-1]-height[ind-1-j]));
            }
            dp[ind]=kjump;
     }

     return dp[n];
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
        // Code here
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
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends