class Solution {
    vector<int> parent;
    vector<int> rank;

private:
    int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void unionByRank(int u, int v) {
        int pu = find(u), pv = find(v);

        if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if(rank[pv] > rank[pu]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // Create DSU
        // While creating if a cycle is found parent[u] == parent[v], then {u,v} is the ANS
        vector<int> ans;
        int n = edges.size();
        parent.resize(n+1, 0);
        for(int i=1; i<=n; i++) {
            parent[i] = i;
        }
        rank.resize(n+1, 0);

        for(vector<int> edge: edges) {
            int u = edge[0], v = edge[1];
            if(find(u) == find(v)) {
                ans = {u, v};
                break;
            } else {
                unionByRank(u, v);
            }
        }

        return ans;
    }
};