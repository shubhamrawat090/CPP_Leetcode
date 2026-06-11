class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uniqueElems;
        for(int num: nums) {
            uniqueElems.insert(num);
        }

        int highestStreak = -1;
        /***** for num = 10, if 9 is not present in array then 10 is a possible starting point ******/
        ///// NOTE: DO NOT run loop on nums, only on the set because it can give TLE  
        for(int num: uniqueElems) {
            if(uniqueElems.find(num - 1) == uniqueElems.end()) {
                // possible start point as nums-1 is not present for nums
                int streak = 1;
                int n = num;
                while(uniqueElems.find(n + 1) != uniqueElems.end()) {
                    n++;
                    streak++;
                }
                highestStreak = max(highestStreak, streak);
            }
        }

        return highestStreak == -1 ? 0 : highestStreak;
    }
};