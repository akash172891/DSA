//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &mat) {
        // Code here
        
        
        int V  = mat.size();
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++) if(mat[i][j]==1e8) mat[i][j] = INT_MAX;
        }
        
        
        for(int k=0;k<V;k++) {
            for(int i=0;i<V;i++) {
                for(int j = 0;j<V;j++){
                    if(mat[i][k]!=INT_MAX && mat[k][j]!=INT_MAX)
                    mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                }
            }
        }
        
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++) if(mat[i][j]==INT_MAX) mat[i][j] = 1e8;
        }
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.floydWarshall(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends