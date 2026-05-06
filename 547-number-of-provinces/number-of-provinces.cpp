class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int count = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(i, isConnected, visited);
                count++;
            }
        }
        return count;
    }

    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;

        int n = isConnected.size();
        for(int nbr=0; nbr<n; nbr++) {
            if(nbr == node) continue;
            // NOT Visited and there is an edge between node->nbr
            if(!visited[nbr] && isConnected[node][nbr] == 1) {
                dfs(nbr, isConnected, visited);
            }
        }
    }
};