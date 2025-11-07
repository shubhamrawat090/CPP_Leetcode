class Solution {
public:
    bool hasAlternatingBits(int n) {
        int copy = n;
        int digitsCount = 0;
        while (copy != 0) {
            digitsCount++;
            copy /= 2;
        }

        // This is wrong as it flips trailing 0s as well
        // int notN = ~n;
        int notN = n >> 1;
        int xorVal = n ^ notN;
        int xorNo1s = 0;

        while (xorVal != 0) {
            xorVal &= (xorVal - 1);
            xorNo1s++;
        }

        return xorNo1s == digitsCount;
    }
};