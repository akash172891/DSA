//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int s) {
        // code here
        int n = arr.size();
         int start=0,end=0;
        long long sum=arr[start];
        while(end<n){
            if(sum<s){
                end++;
                sum+=arr[end];
            }
            else if(sum>s){
                sum-=arr[start];
                start++;
            }
            else {
             if(start<=end)   return {start+1,end+1};
             return {-1};
                
            }
        }
        return {-1};
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends