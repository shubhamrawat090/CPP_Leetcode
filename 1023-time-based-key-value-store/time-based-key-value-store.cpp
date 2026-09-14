class TimeMap {
    // key: [{timestamp, value}]
    // search via Binary search in a key
    // if timestamp <= entryTimestamp => store result, try next better timestamp ==> left++
    // else right--
    // if no match found return result = ""
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {
        store = {};
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // If key is not present, return ""
        if(store.find(key) == store.end()) {
            return "";
        }
        string result = "";
        // This line can give TLE because it copies entire searchspace vector
        // USE A REFERENCE INSTEAD
        auto& searchSpace = store[key];
        int n = searchSpace.size();
        int left = 0, right = n-1;

        while(left <= right) {
            int mid = (left + right) / 2;
            if(searchSpace[mid].first <= timestamp) {
                result = searchSpace[mid].second;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */