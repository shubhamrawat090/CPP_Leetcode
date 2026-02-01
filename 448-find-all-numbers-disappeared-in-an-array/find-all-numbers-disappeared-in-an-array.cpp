class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n+1, 0);
        for(int num: nums) {
            temp[num] = 1;
        }

        vector<int> ans;
        for(int i=1; i<=n; i++) {
            if(temp[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};