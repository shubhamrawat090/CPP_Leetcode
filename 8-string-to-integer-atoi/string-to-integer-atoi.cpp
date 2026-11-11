class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int n = s.size();
        int sign = 1;
        bool numFound = false;
        bool signFound = false;

        for (int i = 0; i < n; i++) {
            // 1. !numFound AND !signFound && is whitespace: skip curr iteration
            /* ****** IMPORTANT *******
               Check for '-' OR '+' before not a num, or it will stop prematurely
            */
            /* 2. if '-' AND !numFound AND !signFound :
                    consider number as negative, skip curr iteration
            */
            /* 3. if '+' AND !numFound AND !signFound :
                    consider number as positive, skip curr iteration
            */
            // 4. if (sign found || numFound) AND whitespace: STOP
            // 5. is not num: STOP the loop
            /* 6. is num:
                    Keep adding in ans; if answer goes out of range -> STOP
                    and keep answer INT_MAX or INT_MIN depending on sign
            */

            if (!numFound && !signFound && s[i] == ' ') {
                // cout<<"whitespace; skip"<<endl;
                continue;
            }
            if (s[i] == '-' && numFound == false && signFound == false) {
                // cout<<"sign = -1; skip"<<endl;
                sign = -1;
                signFound = true;
                continue;
            }
            if (s[i] == '+' && numFound == false && signFound == false) {
                // cout<<"sign = +1; skip"<<endl;
                sign = 1;
                signFound = true;
                continue;
            }
            if ((signFound || numFound) && s[i] == ' ') {
                // cout<<"signFound || numFound AND whitespace: STOP"<<endl;
                break;
            }
            if (s[i] < '0' || s[i] > '9') {
                // cout<<"not a num: STOP"<<endl;
                break;
            }
            numFound = true;
            int num = s[i] - '0';
            ans = ans * 10 + num;
            if (sign * ans >= INT_MAX) {
                // cout<<"+ve max rached: STOP"<<endl;
                ans = INT_MAX;
                break;
            }

            if (sign * ans <= INT_MIN) {
                // make -(-INF) so that final return statement balances out the signs with correct value
                ans = 1LL * -1 * INT_MIN; 
                // cout<<"-ve max rached: STOP"<<endl;
                break;
            }
        }

        return ans * sign;
    }
};