class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(n+1, 0);
        for(int num: nums) {
            if(num > 0 && num <= n) {
                temp[num] = 1;
            }
        }

        for(int i=1; i<=n; i++) {
            if(temp[i] == 0) return i;
        }

        return n+1;
    }
};