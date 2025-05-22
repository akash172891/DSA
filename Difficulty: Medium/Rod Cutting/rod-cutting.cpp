// User function Template for C++

class Solution {
  public:
  int fxn(vector<int>& arr, int ind, int sum, vector<vector<int>>&dp) {
      if(sum<0 || ind<0) return 0;
      if(dp[ind][sum]!=-1) return dp[ind][sum];
      
      int take = 0, notake = 0;
      if(sum > ind)
      take = arr[ind] + fxn(arr, ind, sum-ind-1, dp);
      notake = 0+ fxn(arr, ind-1, sum, dp);
      
      return dp[ind][sum] = max(take, notake);
  }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return fxn(price, n-1, n,dp);
        
    }
};