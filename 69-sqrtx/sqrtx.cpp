class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return x;
        int low = 1, high = x, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid <= x / mid) {
                // store the potential answer and go right
                ans = mid;
                low = mid + 1;
            } else {
                // go left
                high = mid - 1;
            }
        }

        return ans;
    }
};