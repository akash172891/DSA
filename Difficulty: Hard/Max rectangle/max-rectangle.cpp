//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  vector<int> stockSpan(vector<int> arr) {
        int n = arr.size();
        int i =0;
        stack<int> st;
        vector<int> ans;
        while(i<n) {
            if(st.empty()) {
                ans.push_back(i+1);
                st.push(i);
                i++;
            }
            else if(arr[st.top()]<arr[i]) {
                ans.push_back(i-st.top());
                st.push(i);
                i++;
            }
            else st.pop();
        }
        return ans;
    }
    int getMaxArea(vector<int> &arr) {
        // Your code here
        
        vector<int> left = stockSpan(arr);
        vector<int>arr2 = arr;
        reverse(arr2.begin(), arr2.end());
        vector<int> right = stockSpan(arr2);
        reverse(right.begin(), right.end());
    
        int ans = INT_MIN;
        for(int i =0;i<arr.size();i++) {
            ans = max(ans, (left[i]+right[i]-1)*arr[i]);
        }
        return ans;
         
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int n = mat[0].size();
        vector<int> arr = mat[0];
        int ans = getMaxArea(arr);
        
        for(int i = 1;i<mat.size();i++) {
            for(int j = 0; j<n;j++) {
                if(mat[i][j] == 0) arr[j] = 0;
                else arr[j]++;
            }
            
            ans = max(ans, getMaxArea(arr));
        }
        return ans;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(mat) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends