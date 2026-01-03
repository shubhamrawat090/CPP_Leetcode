class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorVal = x ^ y;
        // 1   (0 0 0 1)
        // 4   (0 1 0 0)
        // xor (0 1 0 1)
        // hamming weight of xor(no. of 1s) = 2 which is the no. of places they differ
        int ans = 0;
        while(xorVal != 0) {
            ans++;
            xorVal = xorVal & (xorVal - 1);
        }
        return ans;
    }
};