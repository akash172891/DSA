//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // int ans = INT_MAX;
    // int fxn(vector<int> arr, int ind, int cost, int& n, vector<int> &dp) {
    //     if(ind>n) return 0;
    //     if(ind==n-1) {
    //         ans = min(cost, ans);
    //         return cost;
    //     }
        
        
    //     // cout<<"ind "<<ind<<" cost "<<cost;
        
        
    //     //one jump
    //     int onejump=INT_MAX,twojump=INT_MAX;
    //     if(ind+1 < n)
    //         onejump = fxn(arr, ind+1, cost+abs(arr[ind]-arr[ind+1]), n);
           
    //     if(ind+2 < n) 
    //     twojump = fxn(arr, ind+2, cost+abs(arr[ind]-arr[ind+2]), n);
        
    //     return min(onejump, twojump);
        
    // }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n+1,0);
        
        dp[0] = 0;
        if(n>=1) dp[1]=0;
        if(n>=2) dp[2] = abs(height[1]-height[0]);
        
        for(int ind=3;ind<=n;ind++) {
            
            int onejump=INT_MAX,twojump=INT_MAX;
            
                onejump = dp[ind-1] + abs(height[ind-1]-height[ind-2]);
               
                twojump = dp[ind-2]+abs(height[ind-1]-height[ind-3]);
                
                dp[ind] = min(onejump,twojump);
            
        }
        
        return dp[n];
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends