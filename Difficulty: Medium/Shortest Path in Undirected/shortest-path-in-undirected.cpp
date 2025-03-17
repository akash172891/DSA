//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        
        int n = adj.size();
        
        vector<int> dist(n, INT_MAX);
        
        queue<pair<int,int>> q;
        
        q.push({src, 0});
        dist[src] = 0;
        
        while(!q.empty()) {
            
            int node = q.front().first;
            int dis = q.front().second;
            dist[node] = min(dis, dist[node]);
            
            q.pop();
            for(auto it : adj[node]) {
                if(dist[it] == INT_MAX) {
                    q.push({it, dis+1});
                }
                else if(dist[it]> dis+1) q.push({it, dis+1});
            }
            
            
        }
        
        for(int i = 0;i<n;i++) if(dist[i]==INT_MAX) dist[i] = -1;
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends