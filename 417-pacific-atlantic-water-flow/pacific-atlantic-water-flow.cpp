class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));
        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {
            dfs(heights, pac, i, 0, 0);
            dfs(heights, atl, i, m-1, 0);
        }

        for(int j=0; j<m; j++) {
            dfs(heights, pac, 0, j, 0);
            dfs(heights, atl, n-1, j, 0);
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(pac[i][j] && atl[i][j]) ans.push_back({i, j});
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int i, int j, int prevHeight) {
        int n = heights.size(), m = heights[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m) {
            return;
        }

        if(vis[i][j] == true || heights[i][j] < prevHeight) {
            return;
        }

        vis[i][j] = true;

        dfs(heights, vis, i+1, j, heights[i][j]);
        dfs(heights, vis, i-1, j, heights[i][j]);
        dfs(heights, vis, i, j+1, heights[i][j]);
        dfs(heights, vis, i, j-1, heights[i][j]);
    }
};