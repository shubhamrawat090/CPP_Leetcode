class Solution {
public:
    int passwordStrength(string password) {
        int strength = 0;
        vector<int> lowercase(26, 0);
        vector<int> uppercase(26, 0);
        vector<int> digits(10, 0);
        unordered_map<char, int> specialChar;
        string str = "!@#$";

        for (char ch : password) {
            if (ch >= 'a' && ch <= 'z') {
                lowercase[ch - 'a'] = 1;
            } else if (ch >= 'A' && ch <= 'Z') {
                uppercase[ch - 'A'] = 1;
            } else if (ch >= '0' && ch <= '9') {
                digits[ch - '0'] = 1;
            } else {
                if (str.find(ch) != string::npos) {
                    specialChar[ch] = 1;
                }
            }
        }

        for (int val : lowercase) {
            strength += (val * 1);
        }
        for (int val : uppercase) {
            strength += (val * 2);
        }
        for (int val : digits) {
            strength += (val * 3);
        }
        for (auto& entry : specialChar) {
            strength += (entry.second * 5);
        }
        return strength;
    }
};