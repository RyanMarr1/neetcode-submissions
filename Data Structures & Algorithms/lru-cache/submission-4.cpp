class LRUCache {
public:
    struct ListNode {
        int value;
        int key;
        ListNode* next;
        ListNode* prev;
        ListNode() : value(0), key(0), next(nullptr), prev(nullptr) {}
        ListNode(int key, int value) : key(), value(value), next(nullptr), prev(nullptr) {}
        ListNode(int key, int value, ListNode* prev, ListNode* next) : key(key), value(value), next(next), prev(prev) {}
    };

    ListNode* head;
    ListNode* tail;
    int capacity;
    unordered_map<int, ListNode*> cache;
    
    void update_list_order (ListNode* node) {
        ListNode* prevNode = node->prev;
        node->prev->next = node->next;
        node->next->prev = prevNode;
        ListNode* nextNode = head->next;
        head->next = node;
        node->prev = head;
        nextNode->prev = node;
        node->next = nextNode;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new ListNode();
        head->next = new ListNode();
        tail = head->next;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.contains(key)) {
            update_list_order(cache[key]);
            return cache[key]->value;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) {
            update_list_order(cache[key]);
            cache[key]->value = value;
            return;
        }
        if (cache.size() == capacity) {
            ListNode* nodeToDelete = tail->prev;
            cache.erase(nodeToDelete->key);
            nodeToDelete->prev->next = tail;
            tail->prev = nodeToDelete->prev;
            delete nodeToDelete;
        }
        head->next = new ListNode(key, value, head, head->next);
        head->next->next->prev = head->next;
        cache[key] = head->next;
    }
};
