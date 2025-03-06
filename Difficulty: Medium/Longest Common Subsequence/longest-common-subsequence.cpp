//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fxn(string s, string t, int i, int j, vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        int a = 0,  b =0, c = 0;
        if(dp[i][j]!=0) return dp[i][j];
        if(s[i]==t[j]){
            a = 1+ fxn(s, t, i-1, j-1,dp);
        }
        else {
            b = fxn(s,t, i-1, j,dp);
            c = fxn(s, t, i, j-1,dp);
        }
        return dp[i][j]=max({a,b,c});
    }
    int lcs(string &s, string &t) {
        // code here
        
        int m = s.length();
        int n= t.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i=0;i<n;i++) {
            dp[0][i]=0;
        }
        for(int i=0;i<m;i++)dp[i][0]=0;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int a=0,b=0,c=0;
                if(s[i-1]==t[j-1]){
                    a = 1+ dp[i-1][j-1];
                }
                else {
                    b = dp[i-1][j];
                    c = dp[i][j-1];
                }
                dp[i][j]=max({a,b,c});
            }
        }
        
        
        return dp[m][n];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends