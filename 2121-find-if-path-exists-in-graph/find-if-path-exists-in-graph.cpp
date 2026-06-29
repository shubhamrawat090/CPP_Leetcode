class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto& edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);

        queue<int> q;
        q.push(source);
        visited[source] = 1;

        while(!q.empty()) {
            int node = q.front();
            if(node == destination) return true;
            q.pop();
            for(int nbr: adj[node]) {
                if(nbr == destination) return true;
                if(visited[nbr] == 1) continue;
                q.push(nbr);
                visited[nbr] = 1;
            }
        }
        return false;
    }
};