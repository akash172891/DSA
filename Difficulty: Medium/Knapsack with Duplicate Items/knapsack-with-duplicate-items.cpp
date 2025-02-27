//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
   int maxprofit(int n,int w,vector<int>&val,vector<int>&wt,vector<vector<int>>&dp)
    {
        if(n==0||w==0)return 0;
        if(dp[n][w]!=-1)return dp[n][w];
        
        if(wt[n-1]>w)
        {
            return dp[n][w]=maxprofit(n-1,w,val,wt,dp);
        }
        
        return dp[n][w]=max(val[n-1]+maxprofit(n,w-wt[n-1],val,wt,dp),maxprofit(n-1,w,val,wt,dp));
    }
    
    int knapSack(vector<int>& val, vector<int>& wt, int W) {
        // code here
         int n=val.size();
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        return maxprofit(n,W,val,wt,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends