class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> charIdx;
        int n = s.size();
        vector<int> temp(n, 0);
        for(int i=0; i<n; i++) {
            if(charIdx.find(s[i]) != charIdx.end()) {
                // already present
                int idx = charIdx[s[i]];
                temp[idx] = i; // at that position we write a different index
                temp[i] = idx;
            } else {
                // not already present - first time
                charIdx[s[i]] = i;
                temp[i] = i; // at each char we store the index we encounter.
            }
        }

        for(int i=0; i<n; i++) {
            cout<<temp[i]<<" ";
        }

        // BY NOW: If a character is present once then its temp[i] and i will be same.
        // So, find the first one where temp[i] == i
        for(int i=0; i<n; i++) {
            if(temp[i] == i) {
                return i;
            }
        }

        return -1;
    }
};