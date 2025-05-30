// User function template for C++

class Solution {
  public:
    long long subarraySum(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
       long long result = 0,mod=1e9+7;
         
        // Pick starting point
        for (long long i = 0; i < n; i++) {
             result+= arr[i]*(n-i)*(i+1);
            }
        
        return result%mod;
    }
};