// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // G = good version, B = bad version
        // G G G G G G B B B B B B B
        // Sorted use binary search
        int left = 1, right = n;
        int ans = -1;
        while(left <= right) {
            int mid = right + (left - right) / 2;
            if(isBadVersion(mid)) {
                ans = mid;
                right = mid - 1; // first occurence of BAD version
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};