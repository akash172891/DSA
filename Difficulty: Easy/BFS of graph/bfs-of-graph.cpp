//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here4
        
        vector<int> vis(adj.size(), 0);
        
        queue<int> q;
        
        vector<int> ans;
        
        // for(int i=0;i<adj.size();i++) {
            if(!vis[0]) {
                q.push(0);
                while(q.size()!=0) {
                    int num = q.front();
                    
                  if(!vis[num]){
                       ans.push_back(num);
                       vis[num] = 1;
                       for(int i=0; i<adj[num].size();i++) {
                         if(!vis[adj[num][i]]) q.push(adj[num][i]);
                       }
                  }
                  
                  q.pop();
                  
                }
            }
        // }
        
        
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

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends