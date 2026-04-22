class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, m, n);
                    count++;
                }
            }
        }

        // Undo visited changes - OPTIONAL
        // cout<<"BEFORE"<<end;
        // for(int i=0; i<m; i++) {
        //     for(int j=0;j<n; j++) {
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // for(int i=0; i<m; i++) {
        //     for(int j=0;j<n; j++) {
        //         if(grid[i][j] == '2')  {
        //             grid[i][j] = '1';
        //         }
        //     }
        // }
        // cout<<"AFTER"<<end;
        // for(int i=0; i<m; i++) {
        //     for(int j=0;j<n; j++) {
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return count;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, int r, int c) {
        if (i < 0 || j < 0 || i >= r || j >= c || grid[i][j] == '0' ||
            grid[i][j] == '2')
            return;

        grid[i][j] = '2';
        dfs(grid, i + 1, j, r, c);
        dfs(grid, i, j + 1, r, c);
        dfs(grid, i - 1, j, r, c);
        dfs(grid, i, j - 1, r, c);
    }
};