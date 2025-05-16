//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     int dfs(int node,int des,vector<int> adj[],vector<int> &vis)
    {
        
        if(node==des)
            return 1;
            
        int cnt=0;
        for(auto it:adj[node])
        {
            if(vis[it]==-1)
                cnt += dfs(it,des,adj,vis);
            
            else
                cnt += vis[it];
        }
        
        return vis[node] = cnt;
    }
 
    int possible_paths(vector<vector<int>>edges, int n, int s, int d){
        // Code here
        vector<int> adj[n];
        
        for(auto it:edges)
        {
            int u=it[0],v=it[1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(n,-1);
        return dfs(s,d,adj,vis);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, s, d;
        cin >> n >> m >> s >> d;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        int ans = obj.possible_paths(edges, n, s, d);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends