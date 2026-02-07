class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> fruitFreq;
        int start = 0;
        int maxLen = 0;
        for(int end = 0; end < n; end++) {
            fruitFreq[fruits[end]]++;

            while(fruitFreq.size() > 2) {
                fruitFreq[fruits[start]]--;
                if(fruitFreq[fruits[start]] == 0) {
                    fruitFreq.erase(fruits[start]);
                }
                start++;
            }

            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};