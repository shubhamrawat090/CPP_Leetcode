class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;

        vector<bool> numbers(n, true);

        for(int p=2; p<=sqrt(n); ++p) {
            if(numbers[p]) {
                for(int j=p*p; j<n; j+=p) {
                    numbers[j] = false;
                }
            }
        }

        int ans = 0;
        for(int i=2; i<n; i++) {
            if(numbers[i]) ans++;
        }

        return ans;
    }
};