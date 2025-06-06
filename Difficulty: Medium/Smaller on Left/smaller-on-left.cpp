//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        // code here
        stack<int> st;
        int n = arr.size(), i = 0;
        vector<int> ans;
        while(i<n) {
            if(st.empty()) {
                ans.push_back(-1);
                st.push(arr[i]);
                i++;
            }
            else if(st.top()<arr[i]) {
                ans.push_back(st.top());
                st.push(arr[i]);
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
        vector<int> ans = ob.leftSmaller(arr);

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends