class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R = matrix.size(), C = matrix[0].size();
        int i=0, j=C-1;
        while(i>=0 && i<R && j>=0 && j<C) {
            int val = matrix[i][j];
            if(target == val) return true;
            if(target < val) {
                // Go left
                j--;
            } else {
                // Go right
                i++;
            }
        }
        return false;
    }
};