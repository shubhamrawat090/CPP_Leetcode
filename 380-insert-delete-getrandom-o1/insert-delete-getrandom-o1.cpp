class RandomizedSet {
    unordered_map<int, int> pos;
    vector<int> store;

public:
    RandomizedSet() {
        pos = {};
        store = {};
    }

    bool insert(int val) {
        // Already present -> return false
        if (pos.find(val) != pos.end())
            return false;

        store.push_back(val);

        int valIdx = store.size() - 1;

        // Used to pinpoint elem in vector in O(1)
        pos[val] = valIdx;

        return true;
    }

    bool remove(int val) {
        if (pos.find(val) == pos.end())
            return false;

        int valIdx = pos[val];
        int lastIdx = store.size() - 1;

        if (valIdx != lastIdx) {
            int lastElem = store[lastIdx];

            store[valIdx] = lastElem;
            pos[lastElem] = valIdx;
        }

        pos.erase(val);
        store.pop_back();

        return true;
    }

    int getRandom() {
        int randIdx = rand() % store.size();
        return store[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */