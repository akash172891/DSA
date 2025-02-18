//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Your Code Here
        
        int n =arr.size();
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++) mp[arr[i]]++;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[arr[i]]--;
                mp[arr[j]]--;
                if(mp[arr[i]]==0) mp.erase(arr[i]);
                if(mp[arr[j]]==0)mp.erase(arr[j]);
                
                if(mp.find(target-(arr[i]+arr[j]))!=mp.end()) return true;
                mp[arr[i]]++;
                mp[arr[j]]++;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        bool result = solution.hasTripletSum(arr, target);
        cout << (result ? "true" : "false") << "\n";
    }

    return 0;
}
// } Driver Code Ends