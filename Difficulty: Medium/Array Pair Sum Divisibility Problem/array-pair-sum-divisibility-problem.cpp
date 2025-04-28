//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool canPair(vector<int> &nums, int k) {
        // Code here.
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++) m[nums[i]%k]++;
        
        if(nums.size()%2==1 || m[0]%2==1) return false;
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]%k==0){
                if(m[0]>0) m[0]--;
                else return false;
                
            }
            else if(m[k-(nums[i]%k)]>0) m[k-(nums[i]%k)]--;
            else  return false;
        }
        
        return true;
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
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution obj;
        bool ans = obj.canPair(arr, k);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends