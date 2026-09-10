class Solution {
public:
    int romanToInt(string s) {
        int i = 0;
        int n = s.size();
        unordered_map<char, int> mappings;

        mappings['I'] = 1;
        mappings['V'] = 5;
        mappings['X'] = 10;
        mappings['L'] = 50;
        mappings['C'] = 100;
        mappings['D'] = 500;
        mappings['M'] = 1000;

        int result = 0;
        while(i < n) {
            char ch = s[i];
            int num = mappings[ch];
            if(ch == 'I') {
                if(i < n-1) {
                    if(s[i+1] == 'V') {
                        i++;
                        num = 4;
                    } else if(s[i+1] == 'X') {
                        i++;
                        num = 9;
                    }
                }
            } else if(ch == 'X') {
                if(i < n-1) {
                    if(s[i+1] == 'L') {
                        i++;
                        num = 40;
                    } else if(s[i+1] == 'C') {
                        i++;
                        num = 90;
                    }
                }
            } else if(ch == 'C') {
                if(i < n-1) {
                    if(s[i+1] == 'D') {
                        i++;
                        num = 400;
                    } else if(s[i+1] == 'M') {
                        i++;
                        num = 900;
                    }
                }
            } 

            result += num;
            i++;
        }
        return result;
    }
};