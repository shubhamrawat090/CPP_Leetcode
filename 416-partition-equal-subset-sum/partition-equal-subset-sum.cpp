class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int val : nums) {
            sum += val;
        }
        if (sum % 2 != 0) {
            // cannot be broken into 2 equal halves
            return false;
        }
        return isSubsetSum(nums, sum / 2);
    }

private:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();

        vector<bool> prev(sum + 1, false);
        vector<bool> curr(sum + 1, false);
        prev[0] = curr[0] = true;

        // W - sum - j
        // n - i
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                if (j >= arr[i - 1]) {
                    // pick or not pick
                    bool pick = prev[j - arr[i - 1]];
                    bool notPick = prev[j];
                    curr[j] = pick || notPick;
                } else {
                    // no pick
                    bool notPick = prev[j];
                    curr[j] = notPick;
                }
            }
            prev = curr;
        }

        return curr[sum];
    }
};