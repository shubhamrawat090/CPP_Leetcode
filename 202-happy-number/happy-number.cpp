class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        slow = digitSquareSum(slow);
        fast = digitSquareSum(digitSquareSum(fast));
        while (slow != fast && slow != 1 && fast != 1) {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(digitSquareSum(fast));
        }

        return slow == 1 || fast == 1;
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