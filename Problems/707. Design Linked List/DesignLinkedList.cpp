class MyLinkedList {
    struct Node {
        int val;
        Node* prev;
        Node* next;
        Node(int val = 0, Node* next = nullptr, Node* prev = nullptr) {
            this->val = val;
            this->next = next;
            this->prev = prev;
        }
    };

public:
    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    int get(int index) {
        Node* curr = head->next;
        int count = 0;
        while (curr != tail) {
            if (count == index) {
                return curr->val;
            }
            else {
                count++;
                curr = curr->next;
            }
        }
        return -1;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->prev = head;
        newNode->next = head->next;

        head->next->prev = newNode;
        head->next = newNode;
        size++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        newNode->next = tail;
        newNode->prev = tail->prev;

        tail->prev->next = newNode;
        tail->prev = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;
        Node* curr = head;
        Node* newNode = new Node(val);
        int count = 0;
        while (curr != tail) {
            if (count == index) {
                newNode->prev = curr->prev;
                newNode->next = curr->next;

                curr->next->prev = newNode;
                curr->next = newNode;
                size++;
                break;
            }
            else {
                count++;
                curr = curr->next;
            }
        }
    }

    void deleteAtIndex(int index) {
        if (index >= size) {
            return;
        }
        Node* curr = head;
        int count = 0;
        while (curr != tail) {
            if (count == index) {
                curr->next->next->prev = curr;
                curr->next = curr->next->next;
                size--;
                break;
            }
            else {
                count++;
                curr = curr->next;
            }
        }
    }
};