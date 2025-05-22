class Solution {
  public:
  int ans = 0;
  int fxn(string s, string t, int i, int j, vector<vector<int>>& dp) {
      if(i==0 || j ==0) return 0;
      if(dp[i][j]!=-1) return dp[i][j];
      int take =0, notake =0;
      if(s[i-1]==t[j-1]){
          take = 1 + fxn(s, t, i-1, j-1, dp);
      }
      notake = max(fxn(s, t, i-1, j, dp), fxn(s, t, i, j-1, dp));
      ans = max({ans, take, notake});
      return dp[i][j] = take;
  }
    int longestCommonSubstr(string& s, string& t) {
        // your code here
        int m = s.length(), n = t.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                int take =0, notake =0;
              if(s[i-1]==t[j-1]){
                  take = 1 + dp[i-1][j-1];
              }
              notake = max(dp[i-1][j], dp[i][j-1]);
              ans = max({ans, take, notake});
              dp[i][j] = take;
            }
        }
        
        //  fxn(s1, s2, m, n, dp);
         return ans;
    }
};