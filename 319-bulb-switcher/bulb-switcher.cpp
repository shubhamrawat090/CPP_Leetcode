class Solution {
public:
    int bulbSwitch(int n) {
        if(n >= 10000) {
            return (int)sqrt(n);
        }  

        // THIS SOLUTION GIVES TLE
        // 0 - OFF, 1 - ON
        vector<int> bulbs(n, 0);
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j = j + i + 1) {
                if(bulbs[j] == 0) {
                    bulbs[j] = 1;
                } else {
                    bulbs[j] = 0;
                }
            }
        }

        int count = 0;
        for(int bulb: bulbs) {
            if(bulb == 1) {
                count++;
            }
        }
        return count;
    }
};