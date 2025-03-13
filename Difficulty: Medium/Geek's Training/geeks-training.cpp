//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int m = arr.size();
        int n = arr[0].size();
        
        for(int i=1;i<m;i++) {
            for(int j=0; j<n;j++) {
                int up =0, down =0;
                up = arr[i-1][(j+1)%3];
                down = arr[i-1][(j+2)%3];
                arr[i][j] += max(up, down);
            }
        }
        int ans =0;
        for(int i=0;i<n;i++) {
            ans = max(ans, arr[m-1][i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends