class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int first = 0; first < n - 2; first++) {
            // Skip same values for first as well
            if(first > 0 && nums[first] == nums[first-1]) continue;

            int second = first + 1, third = n - 1;
            while (second < third) {
                int sum = nums[first] + nums[second] + nums[third];

                if (sum == 0) {
                    ans.push_back({nums[first], nums[second], nums[third]});

                    // SKIP DUPLICATES
                    int s = second, t = third;

                    while (s < n && nums[s] == nums[second])
                        s++;
                    while (t >= 0 && nums[t] == nums[third])
                        t--;

                    second = s;
                    third = t;
                } else if (sum > 0) {
                    third--;
                } else {
                    second++;
                }
            }
        }
        return ans;
    }
};