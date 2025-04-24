//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    static bool comp(string a ,string b){
	    return (a+b)>(b+a);
	}
    string findLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<string> nums;
        
        for(int i=0;i<n;i++) nums.push_back(to_string(arr[i]));
        
        sort(nums.begin(), nums.end(), comp);
        
        string ans = "";
        for(auto it : nums) ans+=it;
        reverse(ans.begin(), ans.end());
        while(ans.size()>1 && ans.back()=='0')ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
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
        string ans = ob.findLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends