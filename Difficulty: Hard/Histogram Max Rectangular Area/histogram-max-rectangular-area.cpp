//{ Driver Code Starts
// Initial Template for C++

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
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends