//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int>indegree(n,0);

            for(int i=0;i<n;i++){
                for(int j=0;j<adj[i].size();j++){
                    indegree[adj[i][j]]++;

                }
            }



            queue<int>q;
            vector<int>ans;
            for(int i=0;i<n;i++){
                if(indegree[i]==0)q.push(i);
            }

            while(!q.empty()){
                int x=q.front();

                for(auto it:adj[x]){
                    indegree[it]--;
                    if(indegree[it]==0)q.push(it);

                }
                ans.push_back(x);
                q.pop();
            }
            if(ans.size()!=n)return 1;

            return 0;
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
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends