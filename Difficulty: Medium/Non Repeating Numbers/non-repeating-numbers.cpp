//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> singleNumber(vector<int>& nums) {
        // Code here.
       int xxory=0;
        
        for(auto it: nums)
        xxory=xxory^it;
        int number=xxory & -xxory;
        int x=0;
        int y=0;
        for(auto it:nums){
            if(it & number){
                x=x^it;
            }
            else{
                y=y^it;
            }
        }
        nums.clear();
        if(x>y){
            nums.push_back(y);
            nums.push_back(x);
            return nums;
        }
        else{
            nums.push_back(x);
            nums.push_back(y);
            return nums;
        }
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

        Solution ob;
        vector<int> ans = ob.singleNumber(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends