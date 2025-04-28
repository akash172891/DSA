//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        unordered_set<int>st(arr.begin(), arr.end());
        int ans = 0, cnt = 0;
        for(int i =0;i<arr.size();i++) {
            cnt =0;
            if(st.find(arr[i]-1)==st.end()) {
                int num = arr[i];
                while(st.find(num)!=st.end()) {
                    cnt++;
                    ans = max(ans, cnt);
                    num++;
                }
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends