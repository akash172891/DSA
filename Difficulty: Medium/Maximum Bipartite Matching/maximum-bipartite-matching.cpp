//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
     int n, m;
    int dfs(int node, vector<int> &out, vector<int> &vis, vector<vector<int>> &G){
        for (int j = 0; j<m; j++){
            if (G[node][j] && !vis[j]){
                vis[j] = true;
                if (out[j] == -1 or dfs(out[j], out, vis, G)){
                    out[j] = node;
                    return true;
                }
            }
        }
        return false;
    }
	int maximumMatch(vector<vector<int>>&G){
	    n = G.size(), m = G[0].size();
	    int cnt = 0;
	    vector<int> out(m, -1);
	    for (int i = 0; i<n; i++){
	        vector<int> vis(m, 0);
	        if (dfs(i, out, vis, G)){
	            cnt++;
	        }
	    }
	    return cnt;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends