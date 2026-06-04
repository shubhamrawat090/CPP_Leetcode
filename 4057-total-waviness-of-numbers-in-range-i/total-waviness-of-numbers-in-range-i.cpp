class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count = 0;
        for (int num = num1; num <= num2; num++) {
            if (num <= 100)
                continue;

            vector<int> digits = getDigits(num);
            vector<int> peakAndValley = getPeaksAndValley(digits);
            count += peakAndValley[0];
            count += peakAndValley[1];
        }
        return count;
    }

    vector<int> getPeaksAndValley(vector<int>& digits) {
        int peaks = 0;
        int valleys = 0;
        int n = digits.size();
        for (int i = 1; i < n - 1; i++) {
            if (digits[i] > digits[i - 1] && digits[i] > digits[i + 1])
                peaks++;
            if (digits[i] < digits[i - 1] && digits[i] < digits[i + 1])
                valleys++;
        }
        return {peaks, valleys};
    }

    vector<int> getDigits(int num) {
        vector<int> digits;
        while (num > 0) {
            int rem = num % 10;
            num /= 10;
            digits.push_back(rem);
        }
        return digits;
    }
};