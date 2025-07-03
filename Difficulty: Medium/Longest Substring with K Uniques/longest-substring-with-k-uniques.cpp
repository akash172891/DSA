class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
         unordered_map<char,int>mp;
        int maxi=-1;
        int i=0,j=-1;
        while(i>j && i<s.length()){
            if(mp.size()<=k){
                mp[s[i]]++;
                
                if(mp.size()==k){
                maxi=max(maxi,i-j);
            }
            i++;
            }
            else{
                j++;
                if(mp[s[j]]>1){
                    mp[s[j]]--;
                }else{
                    mp.erase(s[j]);
                }
            }
            
            if(i==j){
                i=j+1;
            }
        }
        return maxi;
    }
};