class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        int low = 1, high = x/2;
        int ans = 0;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(mid > x / mid) {
                high = mid - 1;
            } else {
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
};