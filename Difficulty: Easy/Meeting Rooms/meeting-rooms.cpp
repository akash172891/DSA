//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    static bool comp(vector<int>a, vector<int>b) {
        return a[1]<b[1];
    }
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        int n =  arr.size();
        
        
        sort(arr.begin(), arr.end(), comp);
        
        int i = 0 , j = 1;
        
        while(i<n && j<n) {
            if(arr[j][0]<arr[i][1]) return false;
            i++;
            j++;
        }
        return true;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends