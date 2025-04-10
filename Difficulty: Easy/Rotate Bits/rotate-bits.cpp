//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> rotate(int n, int d) {
        // code here.
        int a , b ;
            d = d%16;
            int nn = n<<d ;
            int p = nn>>16 , q = p<<16, r = nn^q ;
            a = r|p ;
            int x = n>>d , y = n<<(16-d) ,z = y>>16, xx = z<<16,yy = xx^y;
            b = x|yy ;
            return {a,b};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, d;
        cin >> n >> d;
        Solution ob;
        vector<int> res = ob.rotate(n, d);
        cout << res[0] << " " << res[1] << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends