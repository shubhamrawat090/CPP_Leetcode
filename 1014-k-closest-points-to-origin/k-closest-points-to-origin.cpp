class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // sort according to custom function
        // for a[i], b[i] = x1,y1. If sqrt(x1^2 + y1^2) < sqrt(x2^2 + y2^2)
        // then a[i] comes first in the array
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 long long distA = 1LL * a[0] * a[0] + 1LL * a[1] * a[1];
                 long long distB = 1LL * b[0] * b[0] + 1LL * b[1] * b[1];
                 return distA < distB;
             });

        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(points[i]);
        }
        return ans;
    }
};