//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    set<vector<int>> st;
    
    void fxn(vector<int>&arr, int ind, vector<int> tmp) {
        if(st.find(tmp)==st.end()) st.insert(tmp);
        if(ind>=arr.size()) return;
        
        // take 
        tmp.push_back(arr[ind]);
        fxn(arr, ind+1, tmp);
        tmp.pop_back();
        fxn(arr, ind+1, tmp);
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
        vector<int>tmp={};
        fxn(arr, 0, tmp);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the number of test cases
    while (t--) {
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<vector<int>> res = ob.subsets(arr);

        // Print result
        for (const auto& subset : res) {
            if (subset.size() == 0) {
                cout << "[]";
            } else
                for (int num : subset) {
                    cout << num << " ";
                }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends