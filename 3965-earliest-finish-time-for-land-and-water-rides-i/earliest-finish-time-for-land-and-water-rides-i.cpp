class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int m = landStartTime.size();
        int n = waterStartTime.size();

        int ans = INT_MAX;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                // land -> water
                int landEnds = landStartTime[i] + landDuration[i];

                int finish1 = max(landEnds, waterStartTime[j]) +
                              waterDuration[j];

                // water -> land
                int waterEnds = waterStartTime[j] + waterDuration[j];

                int finish2 = max(waterEnds, landStartTime[i]) +
                              landDuration[i];

                ans = min(ans, min(finish1, finish2));
            }
        }

        return ans;
    }
};