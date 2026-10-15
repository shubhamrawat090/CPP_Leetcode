class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int> values(101);
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < 101; k++)
                values[k] = 0;

            int uniques = 0;

            for (int j = i; j < n; j++) {
                if (values[nums[j]] == 0) {
                    uniques++;
                    values[nums[j]] = 1;
                }

                sum += (uniques * uniques);
            }
        }
        return sum;
    }
};