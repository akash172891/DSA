//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
    bool findSwapValues(vector<int>& a, vector<int>& b) {
        // Your code goes here
        // unordered_set<int>st1(a.begin(), a.end());
        unordered_set<int>st2(b.begin(), b.end());
        
        int sum1 = 0, sum2 =0 ,sum =0;
        
        for(auto it:a) sum1+=it;
        for(auto it:b) sum2+=it;
        sum=sum1+sum2;
        if(sum&1) return false;
        sum/=2;
        sum1 = sum-sum1;
        
        for(auto it : a) {
            if(st2.find(it+sum1)!=st2.end()) return true;
        }
        return false;
        
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        // d = crr[0];
        int n = arr.size();
        Solution ob;
        bool ans = ob.findSwapValues(arr, crr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends