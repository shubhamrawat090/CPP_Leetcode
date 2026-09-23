class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                bool isPalindromic = true;
                int left = i, right = j;
                while(left < right) {
                    if(s[left] != s[right]) {
                        isPalindromic = false;
                        break;
                    }
                    left++, right--;
                }
                if(isPalindromic) count++;
            }
        }
        return count;
    }
};