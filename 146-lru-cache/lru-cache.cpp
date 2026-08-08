class LRUCache {
    int size;
    unordered_map<int, int> keyValStore;
    list<int> LRU;

private:
    void insert(int key) {
        if (LRU.size() == size) {
            int delKey = LRU.front();
            LRU.pop_front(); // Remove LRU
            // IMPORTANT: Remove from map as well
            keyValStore.erase(delKey);
        }
        LRU.push_back(key);
    }

    void update(int key) {
        auto it = find(LRU.begin(), LRU.end(), key);
        if (it != LRU.end()) {
            int val = *it; // val == key, can omit this line as well
            // Reinsert at back to make MRU
            LRU.erase(it);
            LRU.push_back(val);
        }
    }

public:
    LRUCache(int capacity) {
        size = capacity;
        keyValStore = {};
    }

    int get(int key) {
        // cout<<"Before get("<<key<<"): ";
        // print(LRU);
        if (keyValStore.find(key) == keyValStore.end())
            return -1;
        int val = keyValStore[key];
        update(key); // Make this key MRU
        // cout<<"After get("<<key<<"): ";
        // print(LRU);
        return val;
    }

    void put(int key, int value) {
        // cout<<"Before put("<<key<<"): ";
        // print(LRU);
        if (keyValStore.find(key) == keyValStore.end()) {
            // first time adding the value
            insert(key); // Insert in LRU
        } else {
            update(key);
        }
        keyValStore[key] = value;
        // cout<<"After put("<<key<<"): ";
        // print(LRU);
    }

    // void print(list<int>& l) {
    //     for (auto it = l.begin(); it != l.end(); ++it)
    //         cout << *it << ",";
    //     cout<<endl;
    // }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */