//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool ans = false;
    void dfs(int node, vector<vector<int>>& adj, vector<bool>&vis, int parent) {
        if(ans == true) return;
        vis[node] = true;
        
        for(auto it: adj[node]) {
            if(vis[it]==true && it!=parent) {
                ans=true;
                return;
            }
            else if(vis[it]==false) {
                dfs(it, adj, vis, node);
            }
        }
        vis[node]=false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        
        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> vis(V, false);
        // bool ans = false;
        
        for(int i=0;i<V;i++) {
            
            if(vis[i]==false) {
                dfs(i, adj, vis, -1);
            }
            if(ans) return ans;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends