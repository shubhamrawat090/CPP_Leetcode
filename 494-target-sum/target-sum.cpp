class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // return recursive(nums, target, 0, 0);

        // int totalSum = 0;
        // for(int val: nums) {
        //     totalSum += val;
        // }
        // vector<vector<int>> dp(nums.size() + 1, vector<int>(2*totalSum + 1,
        // -1)); // can go -totalSum to +totalSum. Hence, we need to shift
        // indices to sum + totalSum return memoized(nums, target, 0, 0, dp,
        // totalSum);

        return tabulate(nums, target);
    }

    int memoized(vector<int>& nums, int& target, int sum, int i,
                 vector<vector<int>>& dp, int& totalSum) {
        int n = nums.size();
        if (i == n) {
            return sum == target ? 1 : 0;
        }

        if (dp[i][sum + totalSum] != -1) {
            return dp[i][sum + totalSum];
        }

        // pick - make curr num minus(-), notPick - keep curr num plus(+)
        int pick = memoized(nums, target, sum - nums[i], i + 1, dp, totalSum);
        int notPick =
            memoized(nums, target, sum + nums[i], i + 1, dp, totalSum);
        return dp[i][sum + totalSum] = pick + notPick;
    }

    int tabulate(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int val : nums) {
            totalSum += val;
        }
        if(abs(target) > totalSum) return 0; // impossible to achieve
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(2 * totalSum + 1, 0));
        int offset = totalSum;
        // sum can be -totalSum to + totalSum
        // at i = 0 (0 elements), sum = 0, there is 1 way to make that target
        // which is empty sum base case: 1st row looks like sum index →

        //       -6 -5 -4 -3 -2 -1  0  1  2  3  4  5  6
        // i=0    0  0  0  0  0  0  1  0  0  0  0  0  0

        // after using first number:

        // i=1
        // ways to reach each sum
        dp[0][0 + offset] = 1;

        for (int i = 1; i < n + 1; i++) {
            for (int s = -totalSum; s <= totalSum; s++) {
                // check if it is inside the range of -totalSum to +totalSum
                int pick = 0, notPick = 0;
                if (s - nums[i - 1] >= -totalSum) {
                    pick = dp[i - 1][s - nums[i - 1] + offset];
                }

                if (s + nums[i - 1] <= totalSum) {
                    notPick = dp[i - 1][s + nums[i - 1] + offset];
                }
                dp[i][s + offset] = pick + notPick;
            }
        }

        return dp[n][target + offset];
    }

    int recursive(vector<int>& nums, int& target, int sum, int i) {
        int n = nums.size();
        if (i == n) {
            return sum == target ? 1 : 0;
        }

        // pick - make curr num minus(-), notPick - keep curr num plus(+)
        int pick = recursive(nums, target, sum - nums[i], i + 1);
        int notPick = recursive(nums, target, sum + nums[i], i + 1);
        return pick + notPick;
    }
};