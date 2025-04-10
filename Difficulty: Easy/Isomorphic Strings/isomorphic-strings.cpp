//{ Driver Code Starts
// C++ program to check if two strings are isomorphic

#include <bits/stdc++.h>

using namespace std;
#define MAX_CHARS 256


// } Driver Code Ends

class Solution {
  public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string &s1, string &s2) {
        if(s1.length()!=s2.length()) return false;

        // Your code here
        unordered_map<char, char> mp, dp;
        
        
        for(int i = 0 ; i<s1.length();i++) {
            if(mp.find(s1[i])==mp.end() && dp.find(s2[i])==dp.end()) {
                mp[s1[i]] = s2[i];
                dp[s2[i]] = s1[i];
            }
            else if(mp.find(s1[i])!=mp.end() && dp.find(s2[i])!=dp.end()) {
                if(mp[s1[i]] != s2[i] || dp[s2[i]]!=s1[i]) return false;
            }
            else return false;
        }
        return true;
        
    }
};


//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    string s1, s2;
    while (t--) {
        cin >> s1;
        cin >> s2;
        Solution obj;
        int r = obj.areIsomorphic(s1, s2);
        if (r) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends