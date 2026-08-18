class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // STOP IF ALL ELEMENTS VISITED ??? HOW TO CHECK ---> *** TODO ***
        // 0. Push elem in result
        // RIGHT : next elem -> matrix[i][j+1]
        // 1. Curr elem -> check am I on boundary? -> if j==cols-1 OR
        // matrix[i][j+1] == VISITED
        // 2. YES IN BOUBDARY -> CHANGE BOUNDARY, R -> D -> L -> U --cycle
        // back-> R

        // DOWN : next elem -> matrix[i+1][j]
        // Am I on boundary? if i == rows - 1 || matrix[i+1][j] == VISITED

        // LEFT : next elem -> matrix[i][j-1]
        // Am I on boundary? if j == 0 || matrix[i][j-1] == VISITED

        // UP : next elem -> matrix[i-1][j]
        // Am I on boundary? if i == 0 || matrix[i-1][j] == VISITED

        // VISITED = 101 ===> CONSTRAINT MAX = 100

        int rows = matrix.size(), cols = matrix[0].size();
        int elemsLeft = rows * cols;

        int i = 0, j = 0;
        vector<int> ans;
        vector<char> dirs = {'R', 'D', 'L', 'U'};
        int dPtr = 0;

        while (elemsLeft) {
            // cout<<"Dir: "<<dirs[dPtr]<<endl;
            // cout<<"Elem taken: "<<i<<", "<<j<<endl;
            ans.push_back(matrix[i][j]);
            elemsLeft--;
            // mark visited
            matrix[i][j] = 101;

            char dir = dirs[dPtr];

            // Check boundary
            // --> YES: Change boundary: **** NOTE: CHANGE i,j AS WELL ****
            // Next elem: ********* NOTE: ALWAYS GO NEXT ELEM *********
            if (dir == 'R') {
                if (j == cols - 1 || matrix[i][j + 1] == 101) {
                    dPtr = (dPtr + 1) % 4;
                    i++;
                } else {
                    j++;
                }
            } else if (dir == 'D') {
                if (i == rows - 1 || matrix[i + 1][j] == 101) {
                    dPtr = (dPtr + 1) % 4;
                    j--;
                } else {
                    i++;
                }
            } else if (dir == 'L') {
                if (j == 0 || matrix[i][j - 1] == 101) {
                    dPtr = (dPtr + 1) % 4;
                    i--;
                } else {
                    j--;
                }
            } else { // dir == 'U'
                if (i == 0 || matrix[i - 1][j] == 101) {
                    dPtr = (dPtr + 1) % 4;
                    j++;
                } else {
                    i--;
                }
            }
        }

        return ans;
    }
};