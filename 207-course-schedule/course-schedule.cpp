class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);
        for(vector<int> course: prerequisites) {
            int u = course[1], v = course[0];
            adj[u].push_back(v);
        }

        vector<int> indegree(V);
        vector<int> topo;

        for(int i = 0; i<V; i++) {
            for(int it: adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int top = q.front(); q.pop();
            topo.push_back(top);

            for(int it: adj[top]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo.size() == V;
    }
};