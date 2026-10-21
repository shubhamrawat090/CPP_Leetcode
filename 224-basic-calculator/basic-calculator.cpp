class Solution {
public:
    int calculate(string s) {
        // Initialize: num = 0, result = 0, sign = +1

        // digit -> num*10 + (s[i] - 0)

        /* + --> Assume that a number has already been formed
            result += (num * sign)
            num = 0
            sign = +1
        */

        /* - --> Assume that a number has already been formed
            result += (num * sign)
            num = 0
            sign = -1
        */ 

        /* ( --> store prev res + sign, solve inside bracket
            stk.push(result)
            stk.push(sign)

            // RESET
            result = 0
            num = 0
            sign = +1
        */
        
        /* ) --> solve curr, add to prev res stored in stack
            result += (num * sign)

            prev_sign = stk.top(), stk.pop()
            prev_res = stk.top(), stk.pop()

            result = prev_res + (prev_sign * result)

            // Reset
            num = 0
            sign = +1
        */

        // At the end do: result += (num * sign) for last remaining num

        // RETURN result

        int n = s.size();
        stack<int> stk;

        long long num = 0;
        long long result = 0;
        int sign = 1;

        for(int i=0; i<n; i++) {
            if(isdigit(s[i])) {
                num = (num * 10) + (s[i] - '0');
            } else if(s[i] == '+') {
                result += (num * sign);
                num = 0;
                sign = 1;
            } else if(s[i] == '-') {
                result += (num * sign);
                num = 0;
                sign = -1;
            } else if(s[i] == '(') {
                stk.push(result);
                stk.push(sign);

                num = 0;
                result = 0;
                sign = 1;
            } else if(s[i] == ')') {
                result += (num * sign);
                num = 0;

                int stack_sign = stk.top(); stk.pop();
                int prev_res = stk.top(); stk.pop();

                result *= stack_sign;
                result += prev_res;
            }
        }

        result += (num * sign);

        return result;
    }
};