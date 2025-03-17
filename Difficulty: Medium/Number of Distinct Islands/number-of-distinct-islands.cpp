//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
     void dfs(vector<vector<int>>& grid, int i, int j, int bi, int bj, vector<pair<int, int>>& shape) {
        int m = grid.size(), n = grid[0].size();
        
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1) return;
        
        grid[i][j] = -1; // Mark visited
        shape.push_back({i - bi, j - bj}); // Store relative position
        
        dfs(grid, i + 1, j, bi, bj, shape);
        dfs(grid, i - 1, j, bi, bj, shape);
        dfs(grid, i, j + 1, bi, bj, shape);
        dfs(grid, i, j - 1, bi, bj, shape);
    }
    
    public: 
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<vector<pair<int, int>>> uniqueShapes;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    vector<pair<int, int>> shape;
                    dfs(grid, i, j, i, j, shape);
                    
                    // **Sorting ensures a consistent order for comparison**
                    sort(shape.begin(), shape.end());
                    
                    uniqueShapes.insert(shape);
                }
            }
        }

        return uniqueShapes.size();
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends