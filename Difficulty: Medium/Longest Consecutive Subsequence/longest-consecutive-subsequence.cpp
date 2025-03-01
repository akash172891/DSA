//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    
    int fxn(int ind , vector<int>arr, int prev, int curr) {
        
        
        
        
        
    }
    
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        
        unordered_set<int>st;
        int n = arr.size();
        
        for(int i=0;i<n;i++) {
            st.insert(arr[i]);
        }
        int ans =0;
        for(int i=0;i<n;i++){
            if(st.find(arr[i]-1)==st.end()){
                int k = arr[i];
                int cnt=0;
                while(st.find(k)!=st.end()){
                    cnt++;
                    k++;
                    ans = max(ans, cnt);
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