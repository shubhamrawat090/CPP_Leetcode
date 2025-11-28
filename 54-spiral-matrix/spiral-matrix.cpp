class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        if(matrix.size() == 0) return res; // No rows in matrix

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        while (left <= right && top <= bottom) {
            // top row
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;

            // right col
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;

            // bottom row
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // left col
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};