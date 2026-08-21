class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto& edge: prerequisites) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
        }

        vector<int> indegree(numCourses, 0);
        for(int u=0; u<numCourses; u++) {
            for(int v: adj[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int u = q.front();
                topo.push_back(u);
                q.pop();
                for(int v: adj[u]) {
                    indegree[v]--;
                    if(indegree[v] == 0) q.push(v);
                }
            }
        }

        return topo.size() == numCourses;
    }
};