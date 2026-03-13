class LRUCache {
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };

    Node* latest;
    Node* oldest;
    int cap;
    unordered_map<int, Node*> cache;

public:
    LRUCache(int capacity) {
        this->cap = capacity;
        this->latest = new Node(0, 0);
        this->oldest = new Node(0, 0);
        this->oldest->next = this->latest;
        this->latest->prev = this->oldest;
        this->cache = {};
    }

    void insert(Node* node) {
        Node* prev = this->latest->prev;
        prev->next = node;
        node->prev = prev;
        node->next = this->latest;
        this->latest->prev = node;
    }

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        Node* node = cache[key];
        remove(node);
        insert(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->val = value;
            remove(node);
            insert(node);
        } else {
            Node* node = new Node(key, value);
            insert(node);
            cache[key] = node;
        }
        
        if (cache.size() > this->cap) {
            Node* lru = this->oldest->next;
            remove(lru);
            cache.erase(lru->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */