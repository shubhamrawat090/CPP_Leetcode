class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        // ALWAYS HAVE nums1 < nums2 SIZE
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);

        int left = 0, right = m; // Right always size of SMALLER ARRAY

        while (left <= right) {
            int partA = (left + right) / 2;
            int partB = (m + n + 1) / 2 - partA;

            //                 partA
            //                   |
            //                   |
            // ------maxLeftA, minRightA -------
            int maxLeftA = (partA == 0) ? INT_MIN : nums1[partA - 1];
            // NOTE: check m instead of m-1 because here we are taking partA and
            // not partA+1
            int minRightA = (partA == m) ? INT_MAX : nums1[partA];

            //                 partB
            //                   |
            //                   |
            // ------maxLeftB, minRightB -------
            int maxLeftB = (partB == 0) ? INT_MIN : nums2[partB - 1];
            int minRightB = (partB == n) ? INT_MAX : nums2[partB];

            if ((maxLeftA <= minRightB) && (maxLeftB <= minRightA)) {
                // POSSIBLE ANSWER

                if ((m + n) % 2 == 0) {
                    return (max(maxLeftA, maxLeftB) +
                            min(minRightA, minRightB)) /
                           2.0;
                } else {
                    // For ODD: take left side value's max
                    return max(maxLeftA, maxLeftB);
                }
            }
            // ALWAYS MOVE ACCORDING TO POINTER partA
            else if (maxLeftA > minRightB) {
                // Take a shorter maxLeftA
                right = partA - 1;
            } else { // maxLeftB > minRightA
                // Take a higher minRightA
                left = partA + 1;
            }
        }

        return 0.0; // ONLY POSSIBLE WHEN NO ELEMENTS IN ARRAY
    }
};