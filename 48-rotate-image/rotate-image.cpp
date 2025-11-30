class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverseRows(matrix);
    }

    void reverseRows(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    void transpose(vector<vector<int>>& matrix) {
        int N = matrix.size();
        for(int i=0; i<N; i++) {
            for(int j=0; j<i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};