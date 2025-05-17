//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool topoSort(int V, vector<vector<int>>& edges) {
        // code here
        int cnt=0;
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        
        queue<int> q;
        
        vector<int> vis(V, 0);
        
        for(int i=0;i<V;i++) {
           if(indegree[i]==0) q.push(i);
        }
        // vector<int> ans;
        
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            
            // indegree[x]--;
            if(indegree[x]==0) cnt++;
            
            for(auto it  : adj[x]) {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
            
            vis[x] = 1;
            
            // dfs(x, adj, vis, indegree); 
        }
        
        if(cnt!=V) return true;
        
        return false;
        
        
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        return topoSort(V, edges);
        
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
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends