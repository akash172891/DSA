//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    string equilibrium(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<int> left(n, 0), right(n,0);
        
        left[0] = arr[0];
        
        for(int i=1;i<n;i++) left[i]=arr[i]+left[i-1];
        
        right[n-1] = arr[n-1];
        
        for(int i = n-2;i>=0;i--) right[i] = arr[i] + right[i+1];
        
        
        for(int i = 0;i<n;i++) if(left[i]==right[i]) return "true";
        return "false";
        
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        string res = obj.equilibrium(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends