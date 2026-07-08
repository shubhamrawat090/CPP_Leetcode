class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // APPROACH - All sums are being generated in normal 3 sum ---> just get the closest sum to target
        int n = nums.size();
        sort(nums.begin(), nums.end()); // N log N

        int ans = INT_MAX;

        for (int first = 0; first < n - 2; first++) { // N
            // Skip same values for first as well
            if (first > 0 && nums[first] == nums[first - 1])
                continue;

            int second = first + 1, third = n - 1;
            while (second < third) { // N / 2 ==> N
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