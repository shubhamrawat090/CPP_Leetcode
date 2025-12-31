class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int val) {
            this->val = val;
            this->next = NULL;
        }

        Node() {
            this->val = 0;
            this->next = NULL;
        }
    };

    Node* head;
    int size;

public:
    MyLinkedList() {
        this->head = NULL;
        this->size = 0;
    }

    int get(int index) {
        if(head == NULL || size == 0 || index >= size) return -1; // Not possible to return a node
        Node* curr = head;
        for(int i=1; i<=index; i++) {
            curr = curr->next;
        }
        return curr->val;
    } 

    void addAtHead(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;
    }

    void addAtTail(int val) {
        if(size == 0 || head == NULL) {
            addAtHead(val);
            return;
        }
        Node* curr = head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new Node(val);
        size++;
    }

    void addAtIndex(int index, int val) {
        if(index > size) {
            return; // Cannot add beyond size of LL
        }

        if(index == 0) {
            addAtHead(val);
            return;
        } else if(index == size) {
            addAtTail(val);
            return;
        }

        Node* curr = head;
        for(int i=1; i<index; i++) {
            curr = curr->next;
        }

        Node* nextNode = curr->next;
        curr->next = new Node(val);
        curr->next->next = nextNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if(head == NULL || size == 0 || index >= size) {
            return; // Cannot delete nodes
        }

        if(index == 0) {
            head = head->next;
            size--;
            return;
        }

        Node* curr = head;
        for(int i=1; i<index; i++) {
            curr = curr->next;
        }

        curr->next = curr->next->next;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */