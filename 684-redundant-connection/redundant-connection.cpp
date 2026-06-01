class Solution {
    struct DSU {
        vector<int> parent;
        vector<int> rank;
        DSU(int n) {
            rank.resize(n+1, 0);
            parent.resize(n+1);
            for(int i=0; i<n; i++) {
                parent[i] = i;
            }
        }

        int find(int u) {
            if(parent[u] == u) return u;
            return parent[u] = find(parent[u]);
        }

        void unionByRank(int u, int v) {
            int pu = find(u);
            int pv = find(v);

            if(rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else if(rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else {
                parent[pu] = pv;
                rank[pv]++;
            }
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        DSU dsu(n);
        for(auto& edge: edges) {
            int u = edge[0], v = edge[1];
            if(dsu.find(u) == dsu.find(v)) {
                ans = {u, v};
            } else {
                dsu.unionByRank(u, v);
            }
        }
        return ans;
    }
};