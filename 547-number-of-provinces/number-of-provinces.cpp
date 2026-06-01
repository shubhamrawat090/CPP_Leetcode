class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                provinces++;
            }
        }
        return provinces;
    }

    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;
        int n = isConnected.size();
        for(int nbr=0; nbr<n; nbr++) {
            if(nbr == node) continue;
            if(!visited[nbr] && isConnected[node][nbr]) dfs(nbr, isConnected, visited);
        }
    }
};