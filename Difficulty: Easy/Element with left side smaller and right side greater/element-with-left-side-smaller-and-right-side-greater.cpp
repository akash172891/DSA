//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findElement(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>left, right;
        left.push_back(0);
        
        
        for(int i=1;i<n;i++) left.push_back(max(left[i-1], arr[i-1]));
        right.push_back(INT_MAX);
        for(int i=n-2;i>=0;i--) right.push_back(min(right.back(), arr[i+1]));
        
        reverse(right.begin(), right.end());
        
        int ans = -1;
        
        for(int i = 1; i<n-1;i++) {
            if(left[i]<arr[i] && right[i]>arr[i]) {
                ans = arr[i];
                break;
            }
        }
        return ans;
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
        int ans = ob.findElement(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends