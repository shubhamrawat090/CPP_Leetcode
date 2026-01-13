class LRUCache {
private:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };

    Node* oldest;
    Node* latest;
    unordered_map<int, Node*> cache;
    int cap;

    void insert(Node* node) {
        Node* prev = latest->prev;
        Node* next = latest;

        prev->next = node;
        next->prev = node;
        node->prev = prev;
        node->next = next;
    }

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }

public:
    LRUCache(int capacity) {
        this->cap = capacity;
        oldest = new Node(0, 0);
        latest = new Node(0, 0);
        oldest->next = latest;
        latest->prev = oldest;
    }

    int get(int key) {
        if(!cache.contains(key)) return -1; // not present in cache
        Node* node = cache[key];
        remove(node);
        insert(node);
        return node->val;
    }

    void put(int key, int value) {
        if(cache.contains(key)) {
            // already present -> update the value
            Node* node = cache[key];
            remove(node);
            insert(node);
            node->val = value;
            return;
        }

        Node* node = new Node(key, value);
        insert(node);
        cache[key] = node;
        if(cache.size() > cap) {
            // Remove the least recently used node
            Node* lru = oldest->next;
            remove(lru);
            cache.erase(lru->key);

            // OPTIONAL: If you want to not have memory leak
            lru->prev = NULL;
            lru->next = NULL;
            delete lru; 
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */