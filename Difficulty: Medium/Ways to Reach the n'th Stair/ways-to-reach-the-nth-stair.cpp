//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int ans =0;
  int fxn(int ind,  vector<int> &dp) {
      int take=0, notake=0;
      if(ind<0) return 0;
      if(ind == 0) {
          
          return 1;
      }
      if(ind  == 1) return 2;
      
      if(dp[ind]!=0) return dp[ind]; 
      if(ind>0) take =  fxn(ind-1, dp);
      if(ind>1) notake =  fxn(ind-2, dp);\
      
      return dp[ind] = take+notake;
      
      
  }
    int countWays(int n) {
        // your code here
        vector<int> dp(n+1, 0);
    
        return fxn(n-1, dp);
        
        
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends