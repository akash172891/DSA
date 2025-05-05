//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        // vector<int> ans;
        stack<int> st;
        int i = 0;
        int n =  arr.size();
        vector<int> ans;
        while(i<n) {
            if(st.empty()) {
                st.push(i);
                ans.push_back(i+1);
                i++;
            }
            else if(arr[st.top()]>arr[i]) {
                ans.push_back(i-st.top());
                st.push(i);
                i++;
            }
            else {
                st.pop();
            }
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
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends