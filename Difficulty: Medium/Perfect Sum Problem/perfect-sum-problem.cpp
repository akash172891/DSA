class Solution {
  public:
    int chc = 0;
    int fxn(vector<int>& arr, int ind, int sum, vector<vector<int>>& dp) {
        if(ind<0 || sum<0) return 0;
        if(ind==0){
             if(arr[0]==0&&sum==0)
             return 2;
             if(arr[0]==sum||sum==0)
             return 1;
             return 0;
         }
        
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        
        int take = fxn(arr, ind-1, sum-arr[ind], dp);
        int notake = fxn(arr, ind-1, sum, dp);
        
        return dp[ind][sum]  = take+notake;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        for(auto it: arr) if(it==0) chc++;
        
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return fxn(arr, n-1, target, dp);
        
    }
};