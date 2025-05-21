class Solution {
  public:
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
    
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        
        int sum = 0;
        int cnt = 0;
        int n = arr.size();
        for(int i=0;i<arr.size();i++) sum+=arr[i];
        
        // for(int i = d;i<=sum;) {
        if((sum-d)&1 || sum<d) return 0;
            int target = (sum-d)/2;
            
            vector<vector<int>> dp(n, vector<int>(target+1, -1));
           cnt+= fxn(arr, n-1, target, dp);
        //     if((i-d)%2==0) {
        //         i+=2;
                
        //     }
        //     else i++;
        // }
        return cnt;
        
        
        
        
    }
};