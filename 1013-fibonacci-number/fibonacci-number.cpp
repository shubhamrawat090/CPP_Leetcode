class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1) return n;
        vector<int> dp(n+1);
        int prevPrev = 0;
        int prev = 1;

        for(int i=2; i<=n; i++) {
            int curr = prev + prevPrev;
            prevPrev = prev;
            prev = curr;
        }
        return prev;
    }
};