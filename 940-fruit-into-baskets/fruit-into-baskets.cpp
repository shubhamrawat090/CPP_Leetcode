class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int distinct = 0;
        unordered_map<int, int> typeCount;
        int n = fruits.size();
        int left = 0;
        int maxLen = -1;
        for (int right = 0; right < n; right++) {
            if (typeCount[fruits[right]] == 0) {
                distinct++;
            }
            typeCount[fruits[right]]++;
            while (distinct > 2) {
                typeCount[fruits[left]]--;
                if (typeCount[fruits[left]] == 0) {
                    distinct--;
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};