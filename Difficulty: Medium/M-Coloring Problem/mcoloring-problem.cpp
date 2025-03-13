//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool safe(int node, vector<int> &color, vector<vector<int>> &adjMatrix, int v, int i){
        for(int j = 0; j < v; j++){
            if(adjMatrix[node][j] == true && color[j] == i){
                return false;
            }
        }
        return true;
    }
    bool solve(int node, vector<int> &color, vector<vector<int>> &adjMatrix, int m, int v){
        if(node == v){
            return true;
        }
        for(int i = 1; i <= m; i++){
            if(safe(node, color, adjMatrix, v, i)){
                color[node] = i;
                if(solve(node + 1, color, adjMatrix, m, v)){
                    return true;
                }
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        vector<int> color(v, 0);
        vector<vector<int>> adjMatrix(v, vector<int>(v, 0));
        for (auto& edge : edges) {
            int u = edge.first;
            int v = edge.second;
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1; 
        }
        if(solve(0, color, adjMatrix, m, v)){
            return true;
        }
        return false;
    }


};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends