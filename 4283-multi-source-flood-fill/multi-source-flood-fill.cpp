class Solution {
public:
    vector<vector<int>> colorGrid(int rows, int cols, vector<vector<int>>& sources) {

        vector<vector<int>> color(rows, vector<int>(cols, 0));
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        queue<vector<int>> q;

        for (auto &s : sources) {
            int r = s[0];
            int c = s[1];
            int clr = s[2];

            color[r][c] = clr;
            dist[r][c] = 0;

            q.push({r, c, clr, 0});
        }

        vector<vector<int>> dirs = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };

        while (!q.empty()) {

            auto top = q.front();
            q.pop();

            int i = top[0];
            int j = top[1];
            int clr = top[2];
            int d = top[3];

            for (auto &dir : dirs) {

                int x = i + dir[0];
                int y = j + dir[1];

                if (x < 0 || x >= rows || y < 0 || y >= cols)
                    continue;

                // First arrival
                if (dist[x][y] > d + 1) {

                    dist[x][y] = d + 1;
                    color[x][y] = clr;

                    q.push({x, y, clr, d + 1});
                }

                // Same-time arrival -> take max color
                else if (dist[x][y] == d + 1 &&
                         color[x][y] < clr) {

                    color[x][y] = clr;

                    q.push({x, y, clr, d + 1});
                }
            }
        }

        return color;
    }
};