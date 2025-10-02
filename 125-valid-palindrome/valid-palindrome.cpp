class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length();

        while(left < right) {
            while(left < s.length() && !isalnum(s[left])) {
                left++;
            }
            while(right >= 0 && !isalnum(s[right])) {
                right--;
            }
            if(left >= right) break;
            if(tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }

        return true;
    }
};