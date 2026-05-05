class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // Points are associated to their indices. means [[0,0],[2,2],[3,10],[5,2],[7,0]. To mark [0,0] visited I mark visited[0] = 1
        vector<int> visited(n, 0); 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); // Distance from first node is 0

        int sum = 0;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int node = top.second;
            int cost = top.first;
            vector<int> nodePoint = points[node];
            int x = nodePoint[0], y = nodePoint[1];

            // Node don't mark visited initially(BEFORE WHILE) because after this while loop won't run
            if(visited[node] == 1) continue; 

            visited[node] = 1;
            sum += cost;

            for(int i=0; i<n; i++) { // All nbr points
                vector<int> nbr = points[i];
                int nx = nbr[0], ny = nbr[1];
                int nCost = abs(x-nx) + abs(y-ny);
                if(!visited[i]) {
                    pq.push({nCost, i});
                }
            }
        }

        return sum;
    }
};