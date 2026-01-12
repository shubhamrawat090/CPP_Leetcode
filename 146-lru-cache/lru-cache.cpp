class LRUCache {
private:
    // NEED Doubly Linked List + Map
    struct Node {
        int key, val;
        Node* next;
        Node* prev;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
    };
    int cap;
    Node* latest;
    Node* oldest;
    unordered_map<int, Node*> cache;

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
        this->oldest = new Node(0, 0);
        this->latest = new Node(0, 0);
        this->oldest->next = this->latest;
        this->latest->prev = this->oldest;
    }

    int get(int key) {
        if (cache.contains(key)) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1; // not present in cache
    }

    void put(int key, int value) {
        if (cache.contains(key)) {
            // if(cache.find(key) != cache.end()) // we can use this also
            Node* existingNode = cache[key];
            remove(existingNode);
            delete existingNode; // AVOID memory leak
        }
        Node* newNode = new Node(key, value);
        insert(newNode);
        cache[key] = newNode;
        if (cache.size() > cap) {
            Node* lru = oldest->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru; // AVOID Memory
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */