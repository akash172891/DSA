//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
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
    int longestPalinSubseq(string &s) {
        // code here
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s,t);
        
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends