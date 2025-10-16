class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        int low = 0, high = x, ans = -1;
        while (low <= high) {
            // int mid = low + (high - low) / 2;
            int mid = (low + high) / 2;
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