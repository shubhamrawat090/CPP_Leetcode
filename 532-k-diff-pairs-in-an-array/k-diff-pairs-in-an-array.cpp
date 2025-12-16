class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // Create a freq hashmap
        // WHEN k == 0, y - x = 0, y == x. This means we need elements which are present >= 2 times => get elements with freq >= 2
        // WHEN k != 0, do the below while searching in the keys of the map
        // for each element x search if x + k also exists or not. 
        // if yes count it.
        unordered_map<int, int> freqMap;
        for(int num: nums) {
            freqMap[num]++;
        }

        int count = 0;

        if(k == 0) {
            for(auto elem: freqMap) {
                if(elem.second >= 2) count++;
            }
        } else {
            for(auto elem: freqMap) {
                int x = elem.first;
                if(freqMap.find(x + k) != freqMap.end()) {
                    count++;
                }
            }
        }

        return count;
    }
};