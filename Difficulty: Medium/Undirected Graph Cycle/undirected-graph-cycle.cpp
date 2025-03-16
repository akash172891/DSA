//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
   void cycleDfs(vector<vector<int>>&adj , int parent, int node, vector<int>& vis, bool &ans){
        if(ans)return;
        for(auto it:adj[node]) {
            if(vis[it]==0) {
                vis[it]=1;
                cycleDfs(adj, node, it, vis, ans);
            }
            else if(vis[it]==1 && it!=parent) {
                ans =true;
                return;
            }
        }
    }
    
    bool cycleBfs(vector<vector<int>>&adj , int src, vector<int>& vis) {
        queue<pair<int,int>> q;
        
        q.push({src, -1});
        vis[src]=1;
        
        while(!q.empty()) {
            
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it :  adj[node]) {
                if(vis[it]==0) {
                    vis[it]=1;
                    q.push({it, node});
                }
                else if(vis[it]==1 && it!=parent) {
                    return true;
                }
            }
            
        }
        return false;
        
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        bool ans = false;
        int n=adj.size();
        vector<int>vis(n+1,0);
        
        for(int i=0;i<n;i++){
            if(ans)break;
            if(vis[i]==0){
                vis[i]=1;
                // cycleDfs(adj, -1, i, vis, ans);
                ans = cycleBfs(adj, i,vis);
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends