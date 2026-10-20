
class LFUCache {
public:
    class Node {
    public:
        int key, value, cnt;
        Node* next;
        Node* prev;

        Node(int key, int value) {
            this->key = key;
            this->value = value;
            cnt = 1;
            next = nullptr;
            prev = nullptr;
        }
    };

    class List {
    public:
        int size;
        Node* head;
        Node* tail;

        List() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addFront(Node* node) {
            Node* temp = head->next;
            node->next = temp;
            node->prev = head;
            head->next = node;
            temp->prev = node;
            size++;
        }

        void removeNode(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }

        Node* removeLast() {
            if (size == 0)
                return nullptr;

            Node* node = tail->prev;
            removeNode(node);
            return node;
        }
    };

    int capacity, minFreq;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* node) {
        int freq = node->cnt;
        freqList[freq]->removeNode(node);

        if (freq == minFreq && freqList[freq]->size == 0) {
            minFreq++;
        }

        node->cnt++;

        if (freqList.find(node->cnt) == freqList.end()) {
            freqList[node->cnt] = new List();
        }

        freqList[node->cnt]->addFront(node);
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }

        Node* node = keyNode[key];
        int value = node->value;
        updateFreq(node);

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        if (keyNode.size() == capacity) {
            List* list = freqList[minFreq];
            Node* node = list->removeLast();

            keyNode.erase(node->key);
            delete node;
        }

        Node* node = new Node(key, value);
        minFreq = 1;

        if (freqList.find(minFreq) == freqList.end()) {
            freqList[minFreq] = new List();
        }

        freqList[minFreq]->addFront(node);
        keyNode[key] = node;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */