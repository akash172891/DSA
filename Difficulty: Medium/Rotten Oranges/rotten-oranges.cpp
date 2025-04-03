//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
         int m = mat.size();
        int n=0;
        if(m!=0) n=mat[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        
        queue<pair<pair<int,int>,int>> q;
        int ans = 0;
        bool noOnes = true;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(mat[i][j]==2){
                    pair<int,int> pr = {i,j};
                    q.push({pr,0});
                    vis[i][j]=2;
                }
                if(mat[i][j]==1) noOnes = false;
            }
        }
        
        if(noOnes) return 0;
        if(q.empty())return -1;
        
        vector<int> drow = {-1, 0 , 0, 1};
        vector<int>dcol = {0, -1, 1, 0};
        
        while(!q.empty()){
            queue<pair<pair<int,int>,int>> q1;
            while(!q.empty()){
                pair<pair<int,int>,int> pr = q.front();
                q.pop();
                int x = pr.first.first;
                int y = pr.first.second;
                int time = pr.second;
                ans = max(ans,time);

                for(int i=0;i<4;i++)  {
                    int row = x + drow[i];
                    int col = y + dcol[i];
                    
                    if(row >=0 && row <m && col >=0 && col<n && mat[row][col]==1 && vis[row][col]==0) {
                        q1.push({{row,col},time+1});
                        vis[row][col]=2;
                    }
                    
                    
                }
                
            }
            q=q1;
            
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0&&mat[i][j]==1)return -1;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends