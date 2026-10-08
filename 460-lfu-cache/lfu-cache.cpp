class LFUCache {
private:
    /*
        Maintain map for freq->list
        1: [1,0], [2,25]....
        2: [5,10]..
        .
        .

        Maintain variables: max_capacity, curr_capacity, min_freq

        Maintain 1 more map: For O(1) search of key, node
        1: Node address for key 1


        Edge Case: When curr node is taken from min_freq and freqList[min_freq]
       is EMPTY ==> minFreq++ 1: .... All Empty 2: [1, 0] ... 2 is the min_freq
       here

        ** USE DOUBLY LINKED LIST(with head, tail nodes already present) FOR
       FASTER DELETION AND ADDITION NODES **

        get(val): search in map, search in list FROM tail end, delete from here,
       put in new freq put(val): update value(if already present), delete from
       here, put in new freq
    */

    struct Node {
        int key;
        int val;
        int freq;

        Node* next;
        Node* prev;

        Node() {
            key = 0;
            val = 0;
            freq = 0;
            next = NULL;
            prev = NULL;
        }

        Node(int k, int v) {
            key = k;
            val = v;
            freq = 1;
            next = NULL;
            prev = NULL;
        }
    };

    struct DLL {
        Node* head;
        Node* tail;
        int size;

        DLL() {
            head = new Node();
            tail = new Node();

            head->next = tail;
            tail->prev = head;

            size = 0;
        }

        void remove(Node* node) {
            if (size == 0)
                return;

            Node* prev = node->prev;
            Node* next = node->next;

            prev->next = next;
            next->prev = prev;

            node->next = NULL;
            node->prev = NULL;

            size--;
        }

        void add(Node* node) {
            Node* first = head->next;

            head->next = node;
            node->prev = head;

            node->next = first;
            first->prev = node;

            size++;
        }
    };

    unordered_map<int, DLL*> freqList;
    unordered_map<int, Node*> keyNode;

    int maxCap;
    int currCap;
    int minFreq;

    void updateFreq(Node* node) {
        int currFreq = node->freq;

        // remove from curr list
        freqList[currFreq]->remove(node);

        if (currFreq == minFreq && freqList[currFreq]->size == 0) {
            minFreq++;
        }

        int newFreq = currFreq + 1;
        node->freq = newFreq;

        if (freqList.find(newFreq) == freqList.end()) {
            // If the DLL is not present for this freq, CREATE ONE
            freqList[newFreq] = new DLL();
        }

        // add to new list
        freqList[newFreq]->add(node);
    }

public:
    LFUCache(int capacity) {
        maxCap = capacity;
        currCap = 0;
        minFreq = 1;
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) { // NOT FOUND
            return -1;
        }

        updateFreq(keyNode[key]);

        return keyNode[key]->val;
    }

    void put(int key, int value) {

        if (maxCap == 0)
            return;

        if (keyNode.find(key) != keyNode.end()) {
            // FOUND

            // update current value
            Node* node = keyNode[key];
            node->val = value;

            updateFreq(node);
        } else {

            // Cache is full, so remove the LFU node BEFORE inserting
            // the new node.
            if (currCap == maxCap) {
                // remove minFreq element
                Node* removeNode = freqList[minFreq]->tail->prev;

                freqList[minFreq]->remove(removeNode);

                keyNode.erase(removeNode->key);
                delete removeNode;

                currCap--;
            }

            // create new node
            Node* node = new Node(key, value);
            keyNode[key] = node;

            if (freqList.find(node->freq) == freqList.end()) {
                // If the DLL is not present for this freq, CREATE ONE
                freqList[node->freq] = new DLL();
            }

            freqList[node->freq]->add(node);

            minFreq = 1;

            currCap++;
        }
    }
};