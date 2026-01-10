class LFUCache {
public:
    class ListNode{
        public:

        int val;
        int key;
        int freque;

        ListNode* next;
        ListNode* prev;

        ListNode(int k, int value){
            val = value;
            key = k;
            freque = 1;
            next = nullptr;
            prev = nullptr;
        }

    };

    int size;
    int minfreq = 0;
    std::unordered_map<int, ListNode*>mp;
    std::unordered_map<int, std::pair<ListNode*, ListNode*>>freq;

    LFUCache(int capacity) {
        this->size = capacity;
    }

    void unlink(ListNode* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void create(int freque){
        ListNode* head = new ListNode(0, 0);
        ListNode* tail = new ListNode(0, 0);
        head->next = tail;
        head->prev = nullptr;
        tail->next = nullptr;
        tail->prev = head;
        freq.insert({freque, {head, tail}});
    }

    void insertAtHead(ListNode* head, ListNode* node){
        node->prev = head;
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
    }

    void delLRU(int minfreq){
        auto it = freq.find(minfreq);
        auto del = it->second;
        ListNode* todel = del.second->prev;
        unlink(todel);
        mp.erase(todel->key);
        if(del.first->next == del.second){
            delete del.first;
            delete del.second;
            freq.erase(minfreq);
        }
        delete todel;
    }

    void replace(ListNode* node) {
        int oldFreq = node->freque;
        ListNode* oldHead = freq[oldFreq].first;
        ListNode* oldTail = freq[oldFreq].second;
        unlink(node);
        if (oldHead->next == oldTail) {
            freq.erase(oldFreq);
            if (minfreq == oldFreq) 
                minfreq++;
            delete oldHead;
            delete oldTail;
        }
        node->freque++; 
        if (freq.find(node->freque) == freq.end())
            create(node->freque);
        insertAtHead(freq[node->freque].first, node);
    }

    void pushToFirst(ListNode* node){
        if(node->next != nullptr)
            unlink(node);
        if(freq.find(1) == freq.end())
            create(1);
        insertAtHead(freq[1].first, node);
        minfreq = 1;
    }

    int get(int key){
        auto get = mp.find(key);
        if(get != mp.end()){
            replace(get->second);
            return get->second->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto have = mp.find(key);
        if(have != mp.end()){
            have->second->val = value;
            replace(have->second);
        }
        else{
            if(mp.size() == size)
                delLRU(minfreq);
            ListNode* node = new ListNode(key, value);
            pushToFirst(node);
            mp.insert({key, node});
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */