class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0], x2 = coordinates[1][0];
        int y1 = coordinates[0][1], y2 = coordinates[1][1];

        int m = y2 - y1, n = x2 - x1;

        for(int i=2; i<coordinates.size(); i++) {
            int x3 = coordinates[i][0], y3 = coordinates[i][1];
            int a = y3 - y1, b = x3 - x1;

            if(m * b != n * a) {
                return false;
            }
        }

        return true;
    }
};