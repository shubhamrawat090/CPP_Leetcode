class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        // If there exists any valid order, then consuming asteroids from smallest → largest will also work.
        // So the greedy strategy is optimal here.
        sort(asteroids.begin(), asteroids.end());
        long long combinedMass = mass;
        int n = asteroids.size();
        for(int i=0; i<n; i++) {
            if(combinedMass < asteroids[i]) return false;
            combinedMass += asteroids[i];
        }
        return true;
    }
};