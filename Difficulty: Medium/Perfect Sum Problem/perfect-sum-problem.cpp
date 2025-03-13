//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int helper(vector<int>& arr, int n, int target, int count, vector<vector<int>> &dp){
        
        //base case
        
        
        if(target == 0){
            
            if(count != 0){
                return pow(2,count);
            }
            
            else{
                return 1;
            }
        }
        
        
        
        if(n == 0)
        return 0;
        
        if(dp[n][target] != -1)
        return dp[n][target];
        
        if(arr[n-1] <= target){
            return dp[n][target] = helper(arr, n-1, target - arr[n-1], count, dp) +
                                   helper(arr, n-1, target, count, dp);
        }
        
        else{
            return dp[n][target] = helper(arr, n-1, target, count, dp);
        }
    }
    
    public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        
        sort(arr.begin(),arr.end());
        int count=0;
        
        for(int i=0; i<n; i++){
            if(arr[i] == 0)
            count++;
        }
        
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        
        return helper(arr, n, target, count, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends