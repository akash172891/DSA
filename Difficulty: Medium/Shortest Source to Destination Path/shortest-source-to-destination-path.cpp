//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        std::queue<std::pair<int, std::pair<int, int>>> q;
        q.push({0,{0,0}});
        vector<vector<int>> vis(N,vector<int>(M,0));
        vis[0][0]=1;
        int nr[4]={-1,1,0,0};
        int nc[4]={0,0,1,-1};
        int ans=1e9;
        if (A[0][0]==0) return -1;
        while (!q.empty()){
            int tm=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            if (row==X and col==Y){
                ans=min(ans,tm);
                continue;
            }
            
            for (int i=0;i<4;i++){
                int r=row+nr[i];
                int c=col+nc[i];
                if (r>=0 and c>=0 and r<N and c<M and A[r][c]==1 and vis[r][c]==0){
                    q.push({tm+1,{r,c}});
                    vis[r][c]=1;
                }
            }
        }
        if (ans==1e9) return -1;
        else return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends