//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  
    int fxn(vector<int> arr, int ind, int k, vector<vector<int>> &dp) {
        if(ind < 0 || k < 0) return 0;
        if(dp[ind][k]!=0) return dp[ind][k];
        
        int take =0, notake =0;
        int length = ind+1;
        
        if(k>=length) {
            take = arr[ind] + fxn(arr, ind, k-length, dp);
        }
        
        notake = fxn(arr, ind-1, k,dp);
        
        return dp[ind][k]=max(take, notake);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        
        int k = n;
        vector<vector<int>> dp(n+1 ,vector<int>(n+1, 0));
        for(int i=0;i<n+1;i++) {
            dp[i][0] = 0;
            dp[0][i] =0;
            
            
        }
        
        
        for(int ind=1;ind<=n;ind++) {
            for(int k = 1;k<=n;k++) {
                int take =0, notake =0;
                int length = ind;
                
                if(k>=length) {
                    take = price[ind-1] + dp[ind][k-length];
                }
                
                notake = dp[ind-1][k];
                
                dp[ind][k]=max(take, notake);
            }
        }
        
        
        
        
        return dp[n][n];
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends