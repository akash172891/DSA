//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   bool ans=true;
    void dfs(int node,int color,vector<int>adj[],int n,vector<int>& vis){
        if(ans==false)return;
            vis[node]=color;
            for(auto it:adj[node]){
                if(vis[it]==-1){
                    vis[it]=1-color;
                    
                    dfs(it,1-color,adj,n,vis);
                }
                else if(vis[it]==color)ans=false;
            }
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int>adj[V];
        
        for(int  i = 0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
         vector<int>vis(V,-1);
	    
	    for(int i=0;i<V;i++){
	        if(vis[i]==-1 && ans){
	            dfs(i,0,adj,V,vis);
	        }
	       
	        
	    }
	    
	    return ans;
        
        
    }
};

// } Driver Code Ends


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            vector<int> temp;
            temp.push_back(v);
            temp.push_back(u);
            edges.push_back(temp);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, edges);
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