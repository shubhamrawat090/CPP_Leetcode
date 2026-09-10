class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // For (u,v) -> edge is v-->u

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto& edge: prerequisites) {
            int v = edge[0], u = edge[1];
            adj[u].push_back(v);
            indegree[v]++; 
        }

        queue<int> q;
        for(int node = 0; node < numCourses; node++) {
            if(indegree[node] == 0) {
                q.push(node);
            }
        }

        vector<int> topo;

        while(!q.empty()) {
            int top = q.front();
            q.pop();
            topo.push_back(top);
            for(auto& nbr: adj[top]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        return topo.size() == numCourses ? topo : vector<int>{};
    }
};