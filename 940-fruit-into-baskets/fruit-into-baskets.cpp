class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0, right = 0;
        int k = 2;
        int maxLen = 0;
        unordered_map<int, int> map;
        while(right < n) {
            map[fruits[right]]++;

            if(map.size() > k) {
                map[fruits[left]]--;
                if(map[fruits[left]] == 0) map.erase(fruits[left]);
                left++;
            }

            if(map.size() <= k) {
                maxLen = max(maxLen, right - left + 1);
            }

            right++;
        }

        return maxLen;
    }
};