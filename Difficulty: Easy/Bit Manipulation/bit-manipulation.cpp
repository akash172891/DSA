//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        i--;
        
        int bitSetter = 1<<i;
        int getBit = (num >> i)&1;
        int setBit = (num|bitSetter);
        int clearBit = (num & ~bitSetter);
        cout<<getBit<<" "<<setBit<<" "<<clearBit;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends