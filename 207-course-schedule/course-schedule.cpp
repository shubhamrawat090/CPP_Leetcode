class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(vector<int>& course: prerequisites) {
            int u = course[1], v = course[0];
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
        return topo.size() == numCourses;
    }
};