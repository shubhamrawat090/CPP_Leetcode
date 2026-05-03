class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int even = 0, odd = 0;
        for(int num: nums) {
            (num % 2 == 0) ? even++ : odd++;
        }

        vector<int> ans;
        for(int num: nums) {
            (num % 2 == 0) ? even-- : odd--;
            ans.push_back((num % 2 == 0) ? odd : even);
        }

        return ans;
    }
};