class LRUCache {
public:

    class ListNode{
        public:

        ListNode* prev;
        ListNode* next;
        int val;
        int key;

        ListNode(int keyi, int value){
            val = value;
            key = keyi;
            prev = nullptr;
            next = nullptr;
        }
    };

    int size;
    std::unordered_map<int, ListNode*>mp;
    ListNode* head;
    ListNode* tail;
    
    LRUCache(int capacity) {
        this->size = capacity;
        head = new ListNode(0, 0);
        tail = new ListNode(0, 0);
        head->next = tail;
        tail->prev = head;
    }
 
    void moveToFront(ListNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void insertToFront(ListNode* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void evictLRU(){
        ListNode* lru = tail->prev;
        lru->prev->next = tail;
        tail->prev = lru->prev;
        mp.erase(lru->key);
        delete lru;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            ListNode* node = mp[key];
            moveToFront(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto have = mp.find(key);
        if(have != mp.end()){
            ListNode* node = mp[key];
            moveToFront(node);
            node->val = value;
        }
        else{
            ListNode* node = new ListNode(key, value);
            insertToFront(node);
            mp[key] = node;
            if(mp.size() > size) evictLRU();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */