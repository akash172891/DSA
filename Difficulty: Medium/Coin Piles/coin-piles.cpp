class Solution {
  public:
     // Question is somewhat not clearly explained
    // So understand what it is stating.
    // We have to choose a element in the array
    // if we chose that element only elements in the this range -> [elem, elem + k] 
    // will be allowed to stay
    // and we need to find such a element, total we keep in the range gets maximum, and minimum we need to remove
    // So we will do it for every distinct element taking it as elem
    int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size();
        // sort the array so that we can chose every element as the start point 
        // This will help us to compute the number of elements smaller than the element very easily
        // Smaller will definitely be removed if we consider that element as starting point
        sort(arr.begin(), arr.end());
        vector<int> prefixSum (n, 0);
        prefixSum[0] = arr[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }
        
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            if(i > 0 && arr[i] == arr[i - 1]){
                continue;
            }
            int prev = i == 0 ? 0 : prefixSum[i - 1];
            // So since we have picked arr[i] as starting point, we can pick only elements in the range from [arr[i], arr[i] + k]
            // We try to pick first element which is greater than arr[i] + k
            int ubIndex = upper_bound(arr.begin() + i, arr.end(), arr[i] + k) - arr.begin();
            // totalToRemove will be sum of total elements lesser than element  + 
            // excess coins present in all those elements which are greater than arr[i] + k
            // we calculate excess coins using -> (prefixSum[n - 1] - prefixSum[ubIndex - 1] - (n - ubIndex)*(arr[i] + k))
            int totalToRemove = prev + (prefixSum[n - 1] - prefixSum[ubIndex - 1] - (n - ubIndex)*(arr[i] + k));
            // as we need to minimise the coins removal, we keep updating our ans
            ans = min(ans, totalToRemove);
            
        }
        return ans;
    }
};
