class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size(), cols = image[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        visited[sr][sc] = 1;
        queue<pair<int, int>> q;
        int originalColor = image[sr][sc];
        q.push({sr, sc});
        image[sr][sc] = color;


        int dirs[][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto top = q.front();
                q.pop();
                int i = top.first, j = top.second;
                for(auto& dir: dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    if(x >= 0 && x < rows && y >= 0 && y < cols) { // within bounds
                        if(image[x][y] == originalColor && visited[x][y] == 0) {
                            visited[x][y] = 1;
                            image[x][y] = color;
                            q.push({x, y});
                        }
                    }
                }
            }
        }
        return image;
    }
};