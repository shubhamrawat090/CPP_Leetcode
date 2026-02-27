class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0)
            return -1;
        queue<pair<int, int>> q;
        int r = grid.size(), c = grid[0].size();
        q.push({0, 0});
        // mark wall - visited
        grid[0][0] = 1;

        vector<vector<int>> dirs = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                                    {-1, -1}, {-1, 1}, {1, 1},  {1, -1}};

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto top = q.front();
                int i = top.first;
                int j = top.second;

                if (i == r - 1 && j == c - 1) {
                    return steps + 1;
                }

                q.pop();

                for (vector<int> dir : dirs) {
                    int x = i + dir[0];
                    int y = j + dir[1];

                    if (x >= 0 && y >= 0 && x < r && y < c && grid[x][y] != 1) {
                        grid[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};