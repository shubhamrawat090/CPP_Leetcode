class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, candidate2 = 0;
        int vote1 = 0, vote2 = 0;
        for (int num : nums) {
            if (candidate1 == num) {
                vote1++;
            } else if (candidate2 == num) {
                vote2++;
            } else if (vote1 == 0) {
                candidate1 = num;
                vote1 = 1;
            } else if (vote2 == 0) {
                candidate2 = num;
                vote2 = 1;
            } else {
                vote1--;
                vote2--;
            }
        }

        int n = nums.size();
        int count1 = 0, count2 = 0;
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            }
        }

        vector<int> ans;
        if(count1 > n/3) {
            ans.push_back(candidate1);
        }
        if(count2 > n/3) {
            ans.push_back(candidate2);
        }
        return ans;
    }
};