class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Staircase Search
        // take top right element as starting point: i = 0, j = cols-1
        // if target > arr[i][j] => go down
        // else target < arr[i][j] => go left
        int rows = matrix.size(), cols = matrix[0].size();
        int i=0, j=cols-1;
        while(i<rows && j>=0) {
            if(matrix[i][j] == target) {
                return true;
            } else if(matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};