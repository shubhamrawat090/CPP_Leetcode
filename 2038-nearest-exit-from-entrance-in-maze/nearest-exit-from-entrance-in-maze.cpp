class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size(), cols = maze[0].size();
        queue<vector<int>> q;
        q.push(entrance);
        // + is walls, . is empty cell, * is visited
        maze[entrance[0]][entrance[1]] = '*';
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int dist = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto top = q.front();
                q.pop();
                int i = top[0], j = top[1];
                // if(i == 0 || j == 0 || i == rows-1 || j == cols-1) {
                //     // Reached boundary
                //     return dist;
                // }

                for(auto& dir: dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    if(x >= 0 && y >= 0 && x < rows && y < cols) { // within bounds
                        if(maze[x][y] == '.') {
                            maze[x][y] = '*';
                            if(x == 0 || y == 0 || x == rows-1 || y == cols-1) {
                                // Reached boundary
                                return dist + 1;
                            }
                            q.push({x, y});
                        }
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};