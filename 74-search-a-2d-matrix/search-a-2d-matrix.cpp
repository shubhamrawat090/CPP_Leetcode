class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0) return false;
        int cols = matrix[0].size();
        int left = 0, right = rows * cols - 1;

        while(left <= right) {
            int pivotIndex = (left + right) / 2;
            int pivotElem = matrix[pivotIndex/cols][pivotIndex%cols];

            if(target == pivotElem) {
                return true;
            } else if(target > pivotElem) {
                left = pivotIndex + 1;
            } else {
                right = pivotIndex - 1;
            }
        }
        return false;
    }
};