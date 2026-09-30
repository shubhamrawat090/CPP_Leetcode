class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int itr = 0;
        int n = nums.size();

        while (itr < n) {
            int curr = itr;
            int nextGr = n;
            for (int i = curr + 1; i < n; i++) {
                if (nums[i] > nums[curr]) {
                    nextGr = i;
                    break;
                }
            }

            if (nextGr == n)
                break;

            swap(nums[++itr], nums[nextGr]);
        }

        return itr + 1;
    }
};