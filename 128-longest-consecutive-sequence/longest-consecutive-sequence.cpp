class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uniqueElems;
        for(int num: nums) {
            uniqueElems.insert(num);
        }

        int highestStreak = -1;
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