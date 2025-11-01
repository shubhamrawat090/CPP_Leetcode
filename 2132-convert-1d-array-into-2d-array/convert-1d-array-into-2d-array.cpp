class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) { // Check if it is possible to create the 2D array
           return {};
        }
        vector<vector<int>> ans(m, vector<int>(n, 0)); // Empty 2D matrix
        int itr = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = original[itr];
                itr++;
            }
        }
        return ans;
    }
};