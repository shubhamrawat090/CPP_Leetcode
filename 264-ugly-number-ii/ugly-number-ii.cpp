class Solution {
public:
    int nthUglyNumber(int n) {
        /*
            Idea:
            1. Every ugly number is formed by multiplying a smaller ugly number by 2, 3, or 5.
            2. Start with 1 as the first ugly number.
            3. Maintain 3 pointers:
            - i2 for multiples of 2
            - i3 for multiples of 3
            - i5 for multiples of 5
            4. Next ugly = min(ugly[i2]*2, ugly[i3]*3, ugly[i5]*5).
            5. Add next ugly to the list.
            6. Move all pointers whose value matched the chosen minimum (to avoid duplicates).
            7. Repeat until nth ugly number is generated.

            Why it works:
            - Generates only valid ugly numbers
            - Always in increasing order
            - No brute force or checking
        */

        vector<long long> ugly(n);
        ugly[0] = 1;

        int i2 = 0, i3 = 0, i5 = 0;

        for (int i = 1; i < n; i++) {
            long long next2 = ugly[i2] * 2;
            long long next3 = ugly[i3] * 3;
            long long next5 = ugly[i5] * 5;

            long long nextUgly = min({next2, next3, next5});
            ugly[i] = nextUgly;

            if (nextUgly == next2)
                i2++;
            if (nextUgly == next3)
                i3++;
            if (nextUgly == next5)
                i5++;
        }

        return ugly[n - 1];
    }
};