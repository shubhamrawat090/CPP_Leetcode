class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) {
            return x;
        }
        int low = 0, high = x, ans;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(mid <= x / mid) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};