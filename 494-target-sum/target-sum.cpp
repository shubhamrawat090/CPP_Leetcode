class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(int val: nums) {
            totalSum += val;
        }

        if(abs(target) > totalSum) return 0; // No possible

        // return recursive(nums, target, 0, 0);

        // int totalSum = 0;
        // for(int val: nums) {
        //     totalSum += val;
        // }
        // vector<vector<int>> dp(nums.size() + 1, vector<int>(2*totalSum + 1,
        // -1)); // can go -totalSum to +totalSum. Hence, we need to shift
        // indices to sum + totalSum return memoized(nums, target, 0, 0, dp,
        // totalSum);

        // return tabulate(nums, target);
        // return spaceOptimize(nums, target);

        // [1, 1, 1, 1, 1], target = 3
        // -1 + 1 + 1 + 1 + 1 = 3,  + [1, 1, 1, 1], -[1]
        // +1 - 1 + 1 + 1 + 1 = 3,  + [1, 1, 1, 1], -[1]
        // +1 + 1 - 1 + 1 + 1 = 3,  + [1, 1, 1, 1], -[1]
        // +1 + 1 + 1 - 1 + 1 = 3,  + [1, 1, 1, 1], -[1]
        // +1 + 1 + 1 + 1 - 1 = 3,  + [1, 1, 1, 1], -[1]

        // We can look it as count number of ways to split it into 2 subsets where the difference is target
        return countPartitions(nums, target);
    }

    int countPartitions(vector<int>& arr, int diff) {
        
        // s1 = sum of subset 1, s2 = sum of subset 2
        // s1 - s2 = diff
        // s1 + s2 = total_sum
        // Adding both we get
        // s1 - s2 + s1 + s2 = diff + total_sum
        // s1 = (diff + total_sum) / 2;
        // Now we need to count the total number of subsets where the sum of a subset = (diff + total_sum) / 2;
        
        int totalSum = 0;
        for(int val: arr) {
            totalSum += val;
        }
        
        
        //////////// VERY VERY IMPORTANT CONDITION /////////////
        if((diff + totalSum) % 2 != 0) {
            return 0; // I don't want s1 to be broken into decimals because it is not possible.
            // Suppose totalSum = 17, diff = 2,
            // s1 = 17 + 2  / 2 = 19/2 = 9.5 this is impossible as all numbers are whole numbers
        } 
        
        int targetSum = (diff + totalSum) / 2;
        
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(targetSum + 1, 0));
        
        dp[0][0] = 1;
        for(int i=1; i<n+1; i++) {
            if(arr[i-1] == 0) {
                dp[i][0] = 2 * dp[i-1][0];
            } else {
                dp[i][0] = dp[i-1][0];
            }
            // dp[i][0] = 1;
        }
        
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<targetSum+1; j++) {
                if(j >= arr[i-1]) {
                    // pick + notPick
                    int pick = dp[i-1][j-arr[i-1]];
                    int notPick = dp[i-1][j];
                    dp[i][j] = pick + notPick;
                } else {
                    // notPick
                    int notPick = dp[i-1][j];
                    dp[i][j] = notPick;
                }
            }
        }
        
        return dp[n][targetSum];
    }

    int spaceOptimize(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int val : nums) {
            totalSum += val;
        }
        if (abs(target) > totalSum)
            return 0; // impossible to achieve
        int n = nums.size();

        vector<int> prevRow(2 * totalSum + 1, 0);
        vector<int> currRow(2 * totalSum + 1, 0);

        int offset = totalSum;
        // sum can be -totalSum to + totalSum
        // at i = 0 (0 elements), sum = 0, there is 1 way to make that target
        // which is empty sum base case: 1st row looks like sum index →

        //       -6 -5 -4 -3 -2 -1  0  1  2  3  4  5  6
        // i=0    0  0  0  0  0  0  1  0  0  0  0  0  0

        // after using first number:

        // i=1
        // ways to reach each sum
        prevRow[0 + offset] = 1;

        for (int i = 1; i < n + 1; i++) {
            for (int s = -totalSum; s <= totalSum; s++) {
                // check if it is inside the range of -totalSum to +totalSum
                int pick = 0, notPick = 0;
                if (s - nums[i - 1] >= -totalSum) {
                    pick = prevRow[s - nums[i - 1] + offset];
                }

                if (s + nums[i - 1] <= totalSum) {
                    notPick = prevRow[s + nums[i - 1] + offset];
                }
                currRow[s + offset] = pick + notPick;
            }
            prevRow = currRow;
        }

        return currRow[target + offset];
    }

    int tabulate(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int val : nums) {
            totalSum += val;
        }
        if (abs(target) > totalSum)
            return 0; // impossible to achieve
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