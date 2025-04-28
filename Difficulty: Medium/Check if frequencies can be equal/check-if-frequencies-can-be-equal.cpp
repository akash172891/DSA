//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        unordered_map<char,int> mp;
        for(auto it:s) mp[it]++;
        int max_freq = INT_MIN, min_freq = INT_MAX;
        
        for(auto it : mp) {
            max_freq = max(max_freq, it.second);
            min_freq = min(min_freq, it.second);
            
        }
        if(max_freq-min_freq >1) return false;
        if(max_freq==min_freq) return true;
        int cnt1 =0, cnt2 = 0;
        for(auto it:mp) {
            if(it.second==max_freq) cnt1++;
            else if(it.second == min_freq) cnt2++;
        }
        if(cnt1==1 || (cnt2 == 1 && min_freq==1)) return true;
        return false;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;

        getline(cin, s);
        Solution ob;
        cout << (ob.sameFreq(s) ? "true" : "false") << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends