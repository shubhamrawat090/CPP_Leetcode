class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackSize = haystack.length(), needleSize = needle.length();
        if(needleSize > haystackSize) return -1;

        for(int i=0; i<haystackSize; i++) {
            if(haystack[i] == needle[0]) {
                if(haystack.substr(i, needleSize) == needle) return i;
            }
        }

        return -1;
    }
};