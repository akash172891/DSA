//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
  bool isPartition(long long mid, vector<int> arr, int n, int k ){
      long long sum = 0;
      int pcount = 0;//painter count
      
      for(int i=0; i<n; i++){
          if(arr[i] > mid) return false;
          sum += arr[i];
          if(sum == mid){
              pcount++;
              sum = 0;
          }else if(sum > mid){
              pcount++;
              sum = arr[i];
          }
      }
      
      if(sum > 0) pcount++;
      if(pcount > k) return false;
      return true;
  }
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        // return minimum time
        int n = arr.size();
        int minn = INT_MAX;
        long long  sum = 0;
        for(int i =0; i<n; i++){
            sum += arr[i];
            minn = min(minn, arr[i]);
        }
        
        long long low = minn;
        long long high = sum;
        long long ans = -1;
        //Binary Search
        while(low <= high){
            long long mid = low + (high-low)/2;
            if(isPartition(mid, arr, n, k)){
                high = mid - 1;
                ans = mid;
            }else{
                low = mid + 1;
            } 
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends