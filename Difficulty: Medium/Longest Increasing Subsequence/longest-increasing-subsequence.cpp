//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fxn(vector<int> &arr, int ind, int prev, vector<vector<int>> &dp) {
        if(ind < 0)return 0;
        if(prev!=-1  && dp[prev][ind]!=0) return dp[prev][ind];
        int take = 0;
        
        if(prev ==-1 || arr[ind] < arr[prev]) 
        take = 1 + fxn(arr, ind-1, ind, dp);
        int notake = fxn(arr, ind-1, prev, dp);
        
        return dp[prev][ind] = max(take, notake);
    }
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>maxi(n, 1);
        int ans=1;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[j]<arr[i]) maxi[i]=max(maxi[i], maxi[j]+1);
            }
            ans=max(ans, maxi[i]);
        }
        
        return ans;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends