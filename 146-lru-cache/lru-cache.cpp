class Node {
public:
    pair<int, int> keyVal;
    Node* next;
    Node* prev;

    Node(pair<int, int> newKeyVal) {
        this->keyVal = newKeyVal;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
    int size;
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;

    void moveToFront(Node* node) {
        if (node == head) return;

        // Remove node from current position
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        if (node == tail) tail = node->prev;

        // Move node to front
        node->next = head;
        node->prev = NULL;
        if (head) head->prev = node;
        head = node;
        if (tail == NULL) tail = head;
    }

    void removeTail() {
        if (tail == NULL) return;

        if (tail->prev) {
            tail->prev->next = NULL;
        } else {
            head = NULL;
        }

        Node* temp = tail;
        tail = tail->prev;
        cache.erase(temp->keyVal.first);
        delete temp;
        size--;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        Node* node = cache[key];
        moveToFront(node);
        return node->keyVal.second;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->keyVal.second = value;
            moveToFront(node);
        } else {
            if (size == capacity) {
                removeTail();
            }

            Node* newNode = new Node({key, value});
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            if (tail == NULL) tail = head;

            cache[key] = newNode;
            size++;
        }
    }
};