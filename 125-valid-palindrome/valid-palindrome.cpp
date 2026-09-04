class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n-1;

        while(left < right) {
            while(left < right && !isalnum(s[left])) left++;
            while(left < right && !isalnum(s[right])) right--;

            if(left >= right) break;

            bool isNumLeft = isdigit(s[left]);
            bool isNumRight = isdigit(s[right]);

            // Either one is not a num;
            // Req condition: either both num or both alphabet
            if((isNumLeft ^ isNumRight) == true) return false;

            // if both alphabet: isNumLeft = isNumRight = false;
            if((isNumLeft && isNumRight) == 0) {
                if(tolower(s[left]) != tolower(s[right])) return false;
            } else {
                // both number
                if(s[left] != s[right]) return false;
            }

            left++, right--;
        }

        return true;
    }
};