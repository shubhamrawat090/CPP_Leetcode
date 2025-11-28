class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverseRows(matrix);
    }

    void reverseRows(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); i++) {
            int l = 0, r = matrix[0].size() - 1;
            while(l < r) {
                swap(matrix[i][l], matrix[i][r]);
                l++, r--;
            }
        }
    }

    void transpose(vector<vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size();
        vector<vector<int>> ans(C, vector<int>(R, 0));
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                ans[j][i] = matrix[i][j];
            }
        }
        
        matrix = ans;
    }
};