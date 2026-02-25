class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count = 0;
        int left = 0, right = 0;
        vector<int> hash(3, 0);
        while(right < n) {
            hash[s[right] - 'a']++;

            while(hash[0] && hash[1] && hash[2]) {
                // shring window
                count += (n - right);
                hash[s[left] - 'a']--;
                left++;
            }

            right++;
        }
        return count;
    }
};