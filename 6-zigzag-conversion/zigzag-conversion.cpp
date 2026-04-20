class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();

        // Fix 1: Handle numRows = 1 immediately to avoid infinite loops
        if (numRows <= 1)
            return s;

        // Using a vector of strings instead of a fixed n*n grid
        // to avoid Memory Limit Exceeded (MLE) on large inputs
        vector<vector<char>> grid(numRows, vector<char>(n, '*'));

        int c = 0;
        int i = 0, j = 0;

        while (c < n) {
            // Fix 2: Vertical Down - Fill the whole column for numRows
            for (i = 0; i < numRows && c < n; i++) {
                grid[i][j] = s[c++];
            }

            // Fix 3: Diagonal Up - Start from row numRows-2 and move up
            // This stops before row 0 to let the next vertical cycle start
            // there
            for (i = numRows - 2; i > 0 && c < n; i--) {
                j++;
                grid[i][j] = s[c++];
            }

            // Increment column for the next vertical drop
            j++;
        }

        // DEBUG
        // for (int row = 0; row < numRows; row++) {
        //     for (int col = 0; col < n; col++) {
        //         cout << grid[row][col] << " ";
        //     }
        //     cout << endl;
        // }

        // Build Ans
        string ans;
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] != '*') {
                    ans.push_back(grid[row][col]);
                }
            }
        }

        return ans;
    }
};