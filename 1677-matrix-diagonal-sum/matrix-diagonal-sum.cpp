class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bool iEqualJ = i == j, iPlusJ = i + j == n - 1;
                if (iEqualJ || iPlusJ) {
                    sum += mat[i][j];
                }
            }
        }

        return sum;
    }
};