//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Your code here
        
        
        
        
        int ans = arr[0];
        for(int i=0;i<arr.size();i++) {
            ans = max(ans, arr[i]);
        }
        if(ans<=0) return ans;
        
        int curr = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]+curr >= 0) curr+=arr[i];
            else curr = 0;
            
            ans = max(curr, ans);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl << "~" << endl;
    }
}
// } Driver Code Ends