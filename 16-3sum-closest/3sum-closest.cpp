class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = INT_MAX;

        for (int first = 0; first < n - 2; first++) {
            // Skip same values for first as well
            if (first > 0 && nums[first] == nums[first - 1])
                continue;

            int second = first + 1, third = n - 1;
            while (second < third) {
                int sum = nums[first] + nums[second] + nums[third];

                if (sum == target) {
                    return target;
                } else if (sum > target) {
                    third--;
                } else {
                    second++;
                }

                if(ans == INT_MAX || abs(ans-target) > abs(sum-target)) ans = sum;
            }
        }
        return ans;
    }
};