class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int ans = 0;
        // ignore starting spaces
        int i = 0;
        for (i = 0; i < n; i++) {
            if (s[i] != ' ')
                break;
        }

        if (i >= n)
            return ans;

        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if(s[i] == '+') {
            sign = 1;
            i++;
        }

        while (i < n) {
            if (s[i] < '0' || s[i] > '9')
                break;

            int digit = s[i] - '0';

            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;

            i++;
        }

        return sign == -1 ? ans * -1 : ans;
    }
};