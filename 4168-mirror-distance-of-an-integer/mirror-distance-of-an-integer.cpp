class Solution {
public:
    int mirrorDistance(int n) {
       int revN = getRev(n);
       return abs(n - revN); 
    }

    int getRev(int n) {
        int ans = 0;
        while(n) {
            ans = ans*10 + (n%10);
            n /= 10;
        }
        return ans;
    }
};