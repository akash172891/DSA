//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    public:
  
   int countsubsets(int index, int target, vector<int>& arr,vector<vector<int>>&dp)
   {
        if(index >= arr.size()){
           
           if(target == 0)return 1;
           else return 0;
        
          
        }
        
       if(dp[index][target]!=-1)return dp[index][target];
       
       int notTake = countsubsets(index-1,target,arr,dp);
       
       int Take = 0;
       if(arr[index]<= target)
       Take = countsubsets(index-1,target-arr[index],arr,dp);
       
       
       return dp[index][target] = (notTake + Take);
   }
   
    int perfectSum(vector<int>& arr, int target) {
        int  n = arr.size();
        
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return countsubsets(n-1,target,arr,dp);
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