class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto& edge: prerequisites) {
            int u = edge[0], v = edge[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;

        vector<int> topo;
        for(int node=0; node<numCourses; node++) {
            if(indegree[node] == 0) {
                q.push(node);
            }
        }

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int top = q.front();
                q.pop();
                topo.push_back(top);
                for(int nbr: adj[top]) {
                    indegree[nbr]--;
                    if(indegree[nbr] == 0) {
                        q.push(nbr);
                    }
                }
            }
        }
        if(topo.size() != numCourses) return {};
        return topo;
    }
};