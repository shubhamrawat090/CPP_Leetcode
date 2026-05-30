class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if (n % groupSize != 0)
            return false;

        unordered_map<int, int> freq;

        for (int x : hand)
            freq[x]++;

        sort(hand.begin(), hand.end());

        for (int start : hand) {

            // already used
            if (freq[start] == 0)
                continue;

            // try making group
            for (int card = start;
                 card < start + groupSize;
                 card++) {

                if (freq[card] == 0)
                    return false;

                freq[card]--;
            }
        }

        return true;
    }
};