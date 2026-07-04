class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& edge : roads) {
            int u = edge[0], v = edge[1], c = edge[2];
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }

        int ans = INT_MAX;
        vector<int> visited(n + 1, 0);
        dfs(1, adj, visited, ans);
        return ans;
    }

    void dfs(int node, vector<vector<pair<int, int>>>& adj,
             vector<int>& visited, int& ans) {
        visited[node] = 1;

        for (auto& nbr : adj[node]) {
            int nbrNode = nbr.first, nbrCost = nbr.second;
            ans = min(ans, nbrCost);
            if (!visited[nbrNode]) {
                dfs(nbrNode, adj, visited, ans);
            }
        }
    }
};