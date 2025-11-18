class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        if (m > n) {
            return findMedianSortedArrays(b, a);
        }

        int left = 0, right = m;
        while (left <= right) {
            int partA = (left + right) / 2;
            int partB = ((m + n + 1) / 2) - partA;

            int maxLeftA = partA == 0 ? INT_MIN : a[partA - 1];
            int minRightA = partA == m ? INT_MAX : a[partA];

            int maxLeftB = partB == 0 ? INT_MIN : b[partB - 1];
            int minRightB = partB == n ? INT_MAX : b[partB];

            if ((maxLeftA <= minRightB) && (maxLeftB <= minRightA)) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftA, maxLeftB) +
                            min(minRightA, minRightB)) /
                           2.0;
                } else {
                    // Assume answer is always on left side -> for ODD
                    return max(maxLeftA, maxLeftB);
                }
            } else if (maxLeftA > minRightB) {
                right = partA - 1;
            } else {
                left = partA + 1;
            }
        }

        return 0.0;
    }
};