class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> typeFreq;
        int n = fruits.size();
        int maxLen = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            typeFreq[fruits[right]]++;
            while(typeFreq.size() > 2) {
                typeFreq[fruits[left]]--;
                if(typeFreq[fruits[left]] == 0) typeFreq.erase(fruits[left]);
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};