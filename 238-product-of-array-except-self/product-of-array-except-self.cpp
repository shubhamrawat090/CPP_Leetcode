class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int productAll = 1, zeroCount = 0;;
        for(int num: nums) {
            if(num == 0) {
                zeroCount++;
            } else {
                productAll *= num;
            }
        }

        for(int num: nums) {
            if(zeroCount == 0) {
                ans.push_back(productAll/num);
            } else if(zeroCount == 1) {
                // we are 0
                if(num == 0) {
                  ans.push_back(productAll);  
                }
                // we are NOT 0, someone else is
                else {
                    ans.push_back(0);
                }
            } else {
                ans.push_back(0);
            }
        }

        return ans;
    }
};