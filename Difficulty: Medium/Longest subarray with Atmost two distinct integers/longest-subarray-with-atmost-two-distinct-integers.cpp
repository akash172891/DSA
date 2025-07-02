class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int ans = 0;
        
        int n = arr.size();
        
        unordered_map<int, int> mp;
        int i = 0, j= 0;
        
        while(i<n && j < n) {
            mp[arr[i]]++;
            
            while(mp.size()>2 && j<=i) {
                mp[arr[j]]--;
                if(mp[arr[j]]==0) mp.erase(arr[j]);
                j++;
            }
            
            ans = max(ans, i-j+1);
            i++;
        }
        
        return ans;
    }
};