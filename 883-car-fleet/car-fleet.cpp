class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> posSpeed;
        for(int i=0; i<n; i++) {
            posSpeed.push_back({position[i], speed[i]});
        }
        sort(posSpeed.begin(), posSpeed.end());

        stack<double> stk;
        for(int i=n-1; i>=0; i--) {
            int pos = posSpeed[i].first, sp = posSpeed[i].second;
            double time = (target - pos) * 1.0 / sp;
            stk.push(time);
            if(stk.size() >= 2) {
                double behindCar = stk.top(); stk.pop();
                double aheadCar = stk.top();
                if(behindCar <= aheadCar) {
                    // We remove the behind car
                    // A (time to reach target = 3)........B (time to reach target = 4)
                    // A or behindCar is removed ==> We don't push it back in stack || we do nothing as already popped
                } else {
                    // We push back in stack because we need the behind car
                    stk.push(behindCar);
                }
            }
        }

        return stk.size();
    }
};