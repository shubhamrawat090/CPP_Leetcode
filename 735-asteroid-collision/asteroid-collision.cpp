class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // Already processed asteroids
        // ↓
        // [10, 2]

        // New asteroid arrives
        //         ↓
        //     -5

        // Check -5 against 2
        // 2 dies

        // Now check -5 against 10
        // 10 dies / survives

        // Keep checking until collision is impossible
        stack<int> stk;

        for(int num: asteroids) {
            if(stk.empty()) {
                stk.push(num);
            } else {
                // try till num can collide and destroy
                bool isNumDestroyed = false;
                while(!stk.empty()) {
                    int top = stk.top();

                    bool canCollide = (top > 0 && num < 0);

                    if(canCollide) {
                        // collision possible
                        if(top > -num) {
                            // num is destroyed
                            isNumDestroyed = true;
                            break;
                        } else if(top < -num) {
                            // top destroyed
                            stk.pop();
                        } else {
                            // both destroyed
                            isNumDestroyed = true;
                            stk.pop();
                            break;
                        }
                    } else {
                        break;
                    }
                }

                if(!isNumDestroyed) {
                    stk.push(num);
                }
            }
        }

        vector<int> remainingAsteroids;
        while(!stk.empty()) {
            remainingAsteroids.push_back(stk.top());
            stk.pop();
        }
        reverse(remainingAsteroids.begin(), remainingAsteroids.end());

        return remainingAsteroids;
    }
};