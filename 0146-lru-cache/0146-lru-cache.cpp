
class LRUCache {
public:
    class Node {
    public:
        int key, value;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            value = v;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node) {
        Node* back = node->prev;
        Node* front = node->next;

        back->next = front;
        front->prev = back;
    }

    void insertAfterHead(Node* node) {
        Node* front = head->next;

        head->next = node;
        node->prev = head;
        node->next = front;
        front->prev = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        deleteNode(node);
        insertAfterHead(node);

        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;

            deleteNode(node);
            insertAfterHead(node);
            return;
        }

        if (mp.size() == cap) {
            Node* lru = tail->prev;
            mp.erase(lru->key);
            deleteNode(lru);
            delete lru;
        }

        Node* node = new Node(key, value);
        mp[key] = node;
        insertAfterHead(node);
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */