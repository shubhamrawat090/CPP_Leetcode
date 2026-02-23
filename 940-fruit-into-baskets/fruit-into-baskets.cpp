class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxLen = 0;
        unordered_map<int, int> map;
        int left = 0;
        for(int right = 0; right < fruits.size(); right++) {
            map[fruits[right]]++;

            if(map.size() == 2) {
                // traverse and count all
                int count = 0;
                for(const auto& itr: map) {
                    count += itr.second;
                }
                maxLen = max(maxLen, count);
            } else if(map.size() > 2) {
                while(map.size() > 2) {
                    map[fruits[left]]--;
                    if(map[fruits[left]] == 0) {
                        map.erase(fruits[left]);
                    }
                    left++;
                }
            }
        }

        if(map.size() == 1) {
            // there was only 1 entry so we need to take that as it wasn't counted before
            for(const auto& itr: map) {
                maxLen = itr.second;
            }
        }
        return maxLen;
    }
};