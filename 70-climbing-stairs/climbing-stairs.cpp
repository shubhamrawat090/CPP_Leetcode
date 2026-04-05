class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;

        int prevPrev = 1;
        int prev = 1;

        for(int i=2; i<=n; i++) {
            int curr = prev + prevPrev;
            prevPrev = prev;
            prev = curr;
        }
        return prev;
    }
};