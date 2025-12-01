class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        while(n > 0) {
            count++;
            n = n & (n-1);
        }
        return count == 1;
    }
};