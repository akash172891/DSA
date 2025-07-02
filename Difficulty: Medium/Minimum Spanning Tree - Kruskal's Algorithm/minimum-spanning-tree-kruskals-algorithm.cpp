// User function Template for C++
class DisjointSet {
    vector<int> Rank, Parent, Size;

public:
    DisjointSet(int n) {
        Rank.resize(n + 1, 0);
        Parent.resize(n + 1);
        Size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            Parent[i] = i;
        }
    }

    int FindUpar(int node) {
        if (Parent[node] == node) return node;
        return Parent[node] = FindUpar(Parent[node]); 
    }

    void UnionByRank(int u, int v) {
        int ulp_u = FindUpar(u);
        int ulp_v = FindUpar(v);

        if (ulp_u == ulp_v) return;

        if (Rank[ulp_u] < Rank[ulp_v]) {
            Parent[ulp_u] = ulp_v;
        } else if (Rank[ulp_u] > Rank[ulp_v]) {
            Parent[ulp_v] = ulp_u;
        } else {
            Parent[ulp_v] = ulp_u;
            Rank[ulp_u]++;
        }
    }

    void UnionBySize(int u, int v) {
        int ulp_u = FindUpar(u);
        int ulp_v = FindUpar(v);

        if (ulp_u == ulp_v) return;

        if (Size[ulp_u] < Size[ulp_v]) {
            Parent[ulp_u] = ulp_v;
            Size[ulp_v] += Size[ulp_u];
        } else {
            Parent[ulp_v] = ulp_u;
            Size[ulp_u] += Size[ulp_v];
        }
    }
};

class Solution {
public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        DisjointSet ds(V);
        vector<vector<int>> newEdges;

        
        for (auto &it : edges) {
            newEdges.push_back({it[2], it[0], it[1]});
        }

        sort(newEdges.begin(), newEdges.end());

        int sum = 0;

        for (auto &it : newEdges) {
            int wt = it[0];
            int u = it[1];
            int v = it[2];

            if (ds.FindUpar(u) != ds.FindUpar(v)) {
                ds.UnionByRank(u, v); 
                sum += wt;
            }
        }

        return sum;
    }
};