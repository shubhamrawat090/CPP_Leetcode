class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // return staircaseSearch(matrix, target);
        return binarySearch(matrix, target);
    }

    bool binarySearch(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1;
        while (low <= high) {
            int midIdx = (low + high) / 2;
            int midElem = matrix[midIdx / n][midIdx % n];

            if (midElem == target) {
                return true;
            } else if (midElem > target) {
                high = midIdx - 1;
            } else {
                low = midIdx + 1;
            }
        }
        return false;
    }

    bool staircaseSearch(vector<vector<int>>& matrix, int target) {
        // Staircase Search
        // take top right element as starting point: i = 0, j = cols-1
        // if target > arr[i][j] => go down
        // else target < arr[i][j] => go left
        int rows = matrix.size(), cols = matrix[0].size();
        int i = 0, j = cols - 1;
        while (i < rows && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};