class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> elemSet;
        for(int num: nums) elemSet.insert(num);

        int maxCount = 0;
        for(int num: elemSet) {
            if(elemSet.find(num-1) == elemSet.end()) {
                // num is a possible start point
                int count = 0;
                int n = num;
                while(elemSet.find(n) != elemSet.end()) {
                    count++;
                    n++;
                }
                maxCount = max(count, maxCount);
            }
        } 

        return maxCount;
    }
};