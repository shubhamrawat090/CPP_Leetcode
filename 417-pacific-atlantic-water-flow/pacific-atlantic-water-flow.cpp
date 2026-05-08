class Solution {
private:
    string pointsToStr(int x, int y) {
        return to_string(x) + "_" + to_string(y);
    }

    vector<int> strToPoints(string str) {
        int pos = str.find('_');

        int x = stoi(str.substr(0, pos));
        int y = stoi(str.substr(pos + 1));

        return {x, y};
    }

    unordered_set<string> bfs(vector<vector<int>>& heights,
                              queue<pair<int, int>>& q,
                              vector<vector<bool>>& visited) {

        int rows = heights.size();
        int cols = heights[0].size();

        unordered_set<string> reachablePoints;

        // Reverse BFS:
        // From ocean border cells, move to neighbors having
        // height >= current cell height.
        // Any reachable cell can flow into this ocean.

        vector<vector<int>> dirs = {
            {0, 1},  // right
            {1, 0},  // down
            {0, -1}, // left
            {-1, 0}  // up
        };

        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            int i = top.first;
            int j = top.second;

            string pointStr = pointsToStr(i, j);

            reachablePoints.insert(pointStr);

            for (auto& dir : dirs) {
                int x = i + dir[0];
                int y = j + dir[1];

                if (x >= 0 && x < rows && y >= 0 && y < cols) {

                    // Reverse flow condition
                    // We can move from current -> neighbor
                    // only if neighbor height >= current height
                    if (heights[x][y] >= heights[i][j] && !visited[x][y]) {

                        visited[x][y] = true;

                        q.push({x, y});
                    }
                }
            }
        }

        return reachablePoints;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        // Pacific Ocean BFS setup
        // Pacific touches:
        // - top row
        // - left column

        queue<pair<int, int>> pacificQ;
        vector<vector<bool>> pacificVisited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            pacificQ.push({i, 0});
            pacificVisited[i][0] = true;
        }

        for (int j = 1; j < cols; j++) {
            pacificQ.push({0, j});
            pacificVisited[0][j] = true;
        }

        // Atlantic Ocean BFS setup
        // Atlantic touches:
        // - bottom row
        // - right column

        queue<pair<int, int>> atlanticQ;
        vector<vector<bool>> atlanticVisited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            atlanticQ.push({i, cols - 1});
            atlanticVisited[i][cols - 1] = true;
        }

        for (int j = 0; j < cols - 1; j++) {
            atlanticQ.push({rows - 1, j});
            atlanticVisited[rows - 1][j] = true;
        }

        unordered_set<string> pacificPoints =
            bfs(heights, pacificQ, pacificVisited);

        unordered_set<string> atlanticPoints =
            bfs(heights, atlanticQ, atlanticVisited);

        vector<vector<int>> ans;

        // Common reachable cells
        for (auto& point : pacificPoints) {

            if (atlanticPoints.count(point)) {

                ans.push_back(strToPoints(point));
            }
        }

        return ans;
    }
};