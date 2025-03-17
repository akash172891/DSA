//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    
     bool fxn(vector<int>& arr, int ind , int sum, vector<vector<int>> &dp) {
       if(sum == 0){
            return true;
       }
       
       if(sum<0 || ind<0) return false;
       
       if(dp[ind][sum]!=0) return dp[ind][sum];
       
       int take =0, notake =0;
       
       if(ind-1>=0) take = fxn(arr, ind-1, sum-arr[ind], dp);
       notake = fxn(arr, ind-1, sum, dp);
       
       return dp[ind][sum] = take||notake;
    
   }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        
        int  n = arr.size();
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        
        for(int i = 0; i<=n;i++) {
            dp[i][0] = 1;
        }
        
        for(int ind=1;ind<=n;ind++) {
            for(int j = 0; j < sum+1; j++) {
                 bool take =0, notake =0;
       
               if(ind-1>=0 && j-arr[ind-1] >=0) take = dp[ind-1][j-arr[ind-1]];
               if(ind-1>=0)notake = dp[ind-1][j];
               
                dp[ind][j] = take||notake;
            }
        }
        
        
        return dp[n][sum];
        
    }
    
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        
        int sum =0;
        
        for(auto it : arr) sum+=it;
        
        if(sum&1) return false;
        
        sum/=2;
        
        return isSubsetSum(arr, sum);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends