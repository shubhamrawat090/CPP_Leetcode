class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        unordered_map<int, int> elemFreq;
        for (int& h : hand) {
            elemFreq[h]++;
        }

        // NOTE: Important to sort because we need shortest element for make groups first
        sort(hand.begin(), hand.end());

        int totalElemsGrouped = 0;

        for (int i = 0; i < n; i++) {
            cout << endl;
            int start = hand[i];
            if (elemFreq[start] == 0) // All occurrences have been grouped
                continue;

            vector<int> currGroup;
            for (int e = start; e <= start + groupSize - 1; e++) {
                if (elemFreq[e] > 0) {
                    currGroup.push_back(e);
                } else {
                    currGroup = {};
                    break;
                }
            }

            // Clear out elems which formed a group
            for(int& e: currGroup) {
                elemFreq[e]--;
            }

            totalElemsGrouped += currGroup.size();
        }

        return totalElemsGrouped == hand.size();
    }
};