class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, ans = 0;
        unordered_map<int, int> fruitFreq;
        for(int right = 0; right < fruits.size(); right++) {
            fruitFreq[fruits[right]]++;

            while(fruitFreq.size() > 2) {
                fruitFreq[fruits[left]]--;
                if(fruitFreq[fruits[left]] == 0) {
                    fruitFreq.erase(fruits[left]);
                }
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};