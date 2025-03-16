//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution {
    
    void dfs(vector<vector<int>> adj, vector<int>&vis, int node) {
        

        vis[node]=1;

        for(auto it : adj[node]) {
            if(!vis[it])dfs(adj,vis,it);
        }
    }
  public:
    int numProvinces(vector<vector<int>> edges, int V) {
        vector<vector<int>> adj(V);
        int n = edges.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) {
                if(edges[i][j]==1) {
                     adj[i].push_back(j);
                    adj[j].push_back(i);
                }

               
            }
        }

        vector<int> vis(V, 0);

        int ans =0;
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                dfs(adj, vis, i);
                ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends