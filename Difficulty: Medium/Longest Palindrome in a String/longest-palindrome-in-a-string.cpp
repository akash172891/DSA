//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &s) {
        // code here
        int l,r;
        int start=0,end=1;
        
        for(int i=1;i<s.length();i++){
            l=i-1;
            r=i;
            while(l>=0&&r<s.length()&&s[l]==s[r]){
                
                if(r-l+1 > end){
                    start=l;
                    end=r-l+1;
                }
                l--;r++;
            }
            l=i-1;
            r=i+1;
            while(l>=0&&r<s.length()&&s[l]==s[r]){
                if(r-l+1 >end){
                    start=l;
                    end=r-l+1;
                }
                l--;r++;
            }
            
            
            
            
        }
        string ans="";
        for(int i=start;i<start+end;i++){
                ans+=s[i];
            }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends