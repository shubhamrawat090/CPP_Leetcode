class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size(), cols = isWater[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(isWater[i][j] == 1) {
                    isWater[i][j] = 0;
                    q.push({i, j});
                } else {
                    isWater[i][j] = -1;
                }
            }
        }

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        int dist = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                pair<int, int> top = q.front();
                q.pop();
                int i = top.first, j = top.second;
                isWater[i][j] = dist; // ACTUALLY MARKING FINAL DISTANCE

                for(vector<int>& dir: dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    if(x >= 0 && x < rows && y >= 0 && y < cols) { // within bounds
                        if(isWater[x][y] == -1) {
                            // NOT ACTUALLY MARKING FINAL DISTANCE
                            isWater[x][y] = INT_MAX; // Just a placeholder for saying it is already visited
                            q.push({x, y});
                        }
                    }
                }
            }
            dist++;
        }

        return isWater;
    }
};