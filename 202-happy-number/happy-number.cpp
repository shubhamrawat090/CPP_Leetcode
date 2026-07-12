class Solution {
public:
    bool isHappy(int n) {
        int count = 0;
        if(n == 1) return true;
        while(count != 50) {
            n = digitSquareSum(n);
            if(n == 1) return true;
            count++;
        }
        return false;
    }

    int digitSquareSum(int n) {
        int sum = 0;
        while (n) {
            int rem = n % 10;
            n /= 10;
            sum += (rem * rem);
        }
        return sum;
    }
};