class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3, 0);
        int left = 0;
        int n = s.size();
        int count = 0;
        for (int right = 0; right < n; right++) {
            freq[s[right] - 'a']++;
            while (containsAll(freq)) {
                freq[s[left] - 'a']--;
                left++;
            }
            /*
                Suppose
                left = 3
                right = 7

                is the smallest valid window ending at right.
                Then the following are all valid:

                0...7
                1...7
                2...7
                3...7

                That's

                left + 1
                substrings.

                So instead of
                count++;
                
                you should do
                count += left + 1;

                after shrinking the window to its minimum valid size.
            */
            count += left;
        }
        return count;
    }

    bool containsAll(vector<int>& freq) {
        return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
    }
};