//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
         unordered_map<ll,ll>mp;
         int n = arr.size();
        
        mp[0]++;
        
        ll sum=0;
        ll ans=0;
        for(ll i=0;i<n;i++){
            sum+=arr[i];
            if(mp.find(sum)!=mp.end()){
                ans+=mp[sum];
                mp[sum]++;
            }
            else mp[sum]++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.findSubarray(arr) << endl;
        cout << "~\n";
    }
}

// } Driver Code Ends