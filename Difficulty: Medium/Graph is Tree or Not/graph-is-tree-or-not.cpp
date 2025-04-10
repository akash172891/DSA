//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int cnt;
    void dfs(vector<int> g[], vector<bool>&vis, int src){
        vis[src]=true;
        for(auto node : g[src]){
            if(!vis[node]){
                cnt++;
                dfs(g,vis,node);
            }
        }
    }
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        // need to check two thing 
        // 1. edges==nodes-1
        // 2. there must be singel connected component (dfs)
        if(m!=n-1)return false;
         
        vector<int> g[n];
        for(auto e: adj){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        cnt=1;
        vector<bool> vis(n,false);
        dfs(g, vis, 0);
        return n==cnt?1:0;
       
        
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends