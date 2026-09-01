class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // m = 3,
        // n = 3
        // nums1 = [1,2,3,0,0,0],
        //              i     p
        // nums2 = [2,5,6],
        //              j
       
        // m = 0,
        // n = 1
        // nums1 = [0],
        //        i p
        // nums2 = [1],
        //          j

        int i = m - 1, j = n - 1;
        int ptr = nums1.size() - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[ptr] = nums1[i];
                ptr--;
                i--;
            } else {
                nums1[ptr] = nums2[j];
                ptr--;
                j--;
            }
        }

        while (i >= 0) {
            nums1[ptr] = nums1[i];
            ptr--;
            i--;
        }
        while (j >= 0) {
            nums1[ptr] = nums2[j];
            ptr--;
            j--;
        }
    }
};