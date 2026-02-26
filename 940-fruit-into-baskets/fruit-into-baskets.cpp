class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0;
        int right = 0;
        unordered_map<int, int> fruitFreq;
        int maxLen = 0;
        while(right < n) {
            fruitFreq[fruits[right]]++;
            while(fruitFreq.size() > 2) {
                fruitFreq[fruits[left]]--;
                if(fruitFreq[fruits[left]] == 0) {
                    fruitFreq.erase(fruits[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};