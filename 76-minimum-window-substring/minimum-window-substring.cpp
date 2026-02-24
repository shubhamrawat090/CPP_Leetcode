class Solution {
public:
    string minWindow(string large, string small) {
        int freq[128] = {0};
        int minLen = INT_MAX, start = 0;
        int left = 0, right = 0;
        int count = 0;
        for(char ch: small) {
            freq[ch]++;
        }
        count = small.size();

        while(right < large.size()) {
            if(freq[large[right]] > 0) {
                count--;
            }
            freq[large[right]]--;

            while(count == 0) {
                int len = right - left + 1;
                if(len < minLen) {
                    start = left;
                    minLen = len;
                }

                freq[large[left]]++;
                if(freq[large[left]] > 0) {
                    count++;
                }
                left++;
            }

            right++;
        }
        return minLen == INT_MAX ? "" : large.substr(start, minLen);
    }
};