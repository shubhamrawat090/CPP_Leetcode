class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> intSymbol;
        intSymbol[1] = "I";
        intSymbol[5] = "V";
        intSymbol[10] = "X";
        intSymbol[50] = "L";
        intSymbol[100] = "C";
        intSymbol[500] = "D";
        intSymbol[1000] = "M";

        // 4 and 9 are special cases:
        // 4: 40, 400
        // 9: 90, 900

        // Maintain a variable to see current powers of 10
        // if 10^0: use I
        // if 10^1: use X
        // if 10^2: use C
        // if 10^3: use M

        vector<string> ans;
        int pow10 = 0;

        while (num) {
            int rem = num % 10;

            int use10sNum = pow(10, pow10);
            string symbol_10s = intSymbol[use10sNum];

            string numRes;

            if (rem == 4 || rem == 9) {
                // special case
                if (pow10 == 0) { // 1
                    if (rem == 4)
                        numRes = "IV";
                    else
                        numRes = "IX";
                } else if (pow10 == 1) { // 10
                    if (rem == 4)
                        numRes = "XL";
                    else
                        numRes = "XC";
                } else if (pow10 == 2) { // 100
                    if (rem == 4)
                        numRes = "CD";
                    else
                        numRes = "CM";
                }
            } else {
                if (rem >= 5) {
                    int use5sNum = 5 * pow(10, pow10);
                    string symbol_5s = intSymbol[use5sNum];

                    numRes = symbol_5s;
                    for(int i=0; i<rem-5; i++) {
                        numRes += symbol_10s;
                    }

                } else {
                    for (int i = 0; i < rem; i++) {
                        numRes += symbol_10s;
                    }
                }
            }

            // cout<<"\nrem: "<<rem;
            // cout<<"\tnumRes: "<<numRes;
            // cout<<"\tpow10: "<<pow10;
            ans.push_back(numRes);
            num /= 10;
            pow10++;
        }

        string result;
        int resSize = ans.size();
        for (int i = resSize - 1; i >= 0; i--) {
            // cout<<ans[i]<<" ";
            result += ans[i];
        }

        return result;
    }
};