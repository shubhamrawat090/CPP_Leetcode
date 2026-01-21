class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // Sort by maximum units
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });

        int totalUnits = 0;

        for(int i=0; i<boxTypes.size(); i++) {
            if(truckSize == 0) break;
            vector<int> boxUnits = boxTypes[i];
            int boxes = boxUnits[0], units = boxUnits[1];
            int size = min(boxes, truckSize);
            totalUnits = totalUnits + size * units;
            truckSize -= size;
        }

        return totalUnits;
    }
};