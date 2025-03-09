//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &arr) {
        // code here
        int n =arr.length();
        int ans = 0;
        for(int i=0;i<n;i++) {
            int  l = i;
            int r = i-1;
            
            //even
            
            
            while(l<n && r>=0){
                
                if(arr[l]==arr[r]) {
                    ans++;
                l++;
                r--;
                
                
                    
                }
                else break;
            }
            
            // odd
            l=i+1;
            r=i-1;
            while(l<n && r>=0) {
                if(arr[l]==arr[r]) {
                    ans++;
                    l++;
                    r--;
                }
                else break;
            }
        }
        
        return ans;
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
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends