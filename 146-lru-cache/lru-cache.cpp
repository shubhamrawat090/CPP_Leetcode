class Node {
    // A Doubly Linked List
    //  prev <- val -> next
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
        // If the node is NOT PRESENT in the cache
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        // If the node is present, we move it to front of cache to make MOST RECENTLY USED
        Node* node = cache[key];
        moveToFront(node);
        // AND WE RETURN THE NODE's VALUE
        return node->keyVal.second;
    }

    void put(int key, int value) {
        // If the key is already present in the cache - MOVE THIS ENTRY TO FRONT
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->keyVal.second = value;
            moveToFront(node);
        } 
        // Key in NOT present in the cache - ADD A NEW ENTRY
        else {
            if (size == capacity) {
                // If cache is full then we remove the last items (LEAST RECENTLY USED)
                removeTail();
            }


            Node* newNode = new Node({key, value});
            newNode->next = head; // ptr --> head
            if (head) head->prev = newNode; // ptr <-- head, complete the doubly link
            head = newNode; // move head 1 step back
            if (tail == NULL) tail = head; // If these was not tail, the added node is the first

            cache[key] = newNode; // add the node to our cache in count the size
            size++;
        }
    }
};