class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate1 = 0, candidate2 = 0;
        int vote1 = 0, vote2 = 0;

        for (int i = 0; i < n; i++) {
            if (candidate1 == nums[i]) {
                vote1++;
            } else if (candidate2 == nums[i]) {
                vote2++;
            } else if (vote1 == 0) {
                candidate1 = nums[i];
                vote1 = 1;
            } else if (vote2 == 0) {
                candidate2 = nums[i];
                vote2 = 1;
            } else {
                vote1--, vote2--;
            }
        }

        // Check if candidate 1 and candidate2 are actually occurring more than
        // n/3 times
        vector<int> ans;
        int count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == candidate1)
                count1++;
            else if (nums[i] == candidate2)
                count2++;
        }

        if (count1 > n / 3)
            ans.push_back(candidate1);
        if (count2 > n / 3)
            ans.push_back(candidate2);

        return ans;
    }
};