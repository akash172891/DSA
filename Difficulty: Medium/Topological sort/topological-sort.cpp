//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
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
        vector<int> ans;
        
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            
            // indegree[x]--;
            if(indegree[x]==0) ans.push_back(x);
            
            for(auto it  : adj[x]) {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
            
            vis[x] = 1;
            
            // dfs(x, adj, vis, indegree); 
        }
        
        if(ans.size()!=V) return {-1};
        
        return ans;
        
        
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        int x = V;
        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(x, res, adj);
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