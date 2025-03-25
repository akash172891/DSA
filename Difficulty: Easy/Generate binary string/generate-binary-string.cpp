//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    vector<string> ans;
    void fxn(string s, int ind, int k) {
        
        if(ind<0 || k==0) {
            ans.push_back(s);
            return;
        }
        if(ind+1 <s.length() && s[ind+1] == '?') return;
        
        if(s[ind] == '?') {
            s[ind] = '0';
            fxn(s, ind-1, k-1);
            s[ind] = '1';
            fxn(s, ind-1, k-1);
            
            s[ind] = '?';
        }
        else {
            fxn(s, ind-1, k);
        }
        
        
    }
	public:
		vector<string> generate_binary_string(string s)
		{
		    // Code here
		    int  k =0, n = s.length();
		    
		    for(auto it : s ) if(it=='?')k++;
		    if(k==0) return {s};
		    
		    fxn(s,n-1,k);
		    sort(ans.begin(), ans.end());
		    
		    return ans;
		}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string s;
	    cin >> s;
	    Solution ob;
	    vector<string> ans = ob.generate_binary_string(s);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends