class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> input, int k) {
        // return usingSort(input, k);
        return usingHeap(input, k);
    }

    vector<vector<int>> usingHeap(vector<vector<int>> input, int k) {
        // maintain k size heap using priority_queue
        // if(heap.size() < k)
        // // then push {dist, currElemXandY}
        // else if(topElem distance from origin > currElem dist from origin)
        // // then remove top element and push {dist, currElemXandY}
        priority_queue<pair<int, vector<int>>> heap;
        for (auto xy : input) {
            int x = xy[0], y = xy[1];
            int dist = x * x + y * y;

            if (heap.size() < k) {
                heap.push({dist, xy});
            } else if (heap.top().first > dist) {
                heap.pop();
                heap.push({dist, xy});
            }
        }

        vector<vector<int>> ans;
        while (!heap.empty()) {
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }

    vector<vector<int>> usingSort(vector<vector<int>> input, int k) {
        // sort according to custom function
        // for a[i], b[i] = x1,y1. If sqrt(x1^2 + y1^2) < sqrt(x2^2 + y2^2)
        // then a[i] comes first in the array
        sort(input.begin(), input.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 long long distA = 1LL * a[0] * a[0] + 1LL * a[1] * a[1];
                 long long distB = 1LL * b[0] * b[0] + 1LL * b[1] * b[1];
                 return distA < distB;
             });

        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(input[i]);
        }
        return ans;
    }
};