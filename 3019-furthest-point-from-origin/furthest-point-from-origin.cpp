class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        // lets say I am at 0.

        // I walk 5 steps RIGHT and 2 steps right 
        // 0 _ _ _ _ R  +5
        // 0 _ L _ _ _  -3
        // At the end I am at dist 2 from origin => R-L
        
        // I walk 2 steps RIGHT and 5 steps right 
        // _ _ 0 _ R  +2
        // L _ 0 _ _  -5
        // At the end I am at dist 2 from origin => -(R-L)

        // *** At the end distance is abs(R-L) ***

        // F_____0       Should go more LEFT to maximise dist.
        // ______0_____F Should go more LEFT to maximise dist.
        // In both case I ADD THE No. of BLANKS

        int blanks = 0, right = 0, left = 0;
        for(char ch: moves) {
            if(ch == 'L') left++;
            else if(ch == 'R') right++;
            else blanks++;
        }
        return abs(right-left) + blanks;
    }
};