class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // return brute(boxTypes, truckSize);
        return better(boxTypes, truckSize);
    }

    int better(vector<vector<int>>& boxTypes, int truckSize) {
        int UNITS_VS_BOXES_SIZE = 1001;
        vector<int> unitsVsBoxes(UNITS_VS_BOXES_SIZE); // size constraint is 1000. 
        for(vector<int>& boxType: boxTypes) {
            int box = boxType[0], units = boxType[1];
            unitsVsBoxes[units] += box;
        }

        int ans = 0;
        // Iterate from back as we need highest units first
        for(int i=UNITS_VS_BOXES_SIZE-1; i>=0; i--) {
            if(truckSize == 0) break;
            int units = i;
            int boxes = unitsVsBoxes[units];
            int size = min(truckSize, boxes);
            ans += (size * units);
            truckSize -= size;
        }
        return ans;
    }

    int brute(vector<vector<int>>& boxTypes, int truckSize) {
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