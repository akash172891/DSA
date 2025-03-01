//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  string carrystring(string &s, int &ind) {
        int count = 0;
        string word = "";
        
        while(ind < s.length()) {
            if(s[ind] >= '0' && s[ind] <= '9'){
                 count*= 10;
                 count+= (s[ind] - '0');
            }
            else if(s[ind]=='['){
                ind++;
                string temp = carrystring(s, ind);
                while(count--) word += temp;
                
                
                count = 0;
            }
            
            else if(s[ind] == ']')
                return word;
            else
                word += s[ind];
            ind++;
        }
        return word;
    }
    string decodedString(string &s) {
        // code here
        int ind =0;
        return carrystring(s,ind);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends