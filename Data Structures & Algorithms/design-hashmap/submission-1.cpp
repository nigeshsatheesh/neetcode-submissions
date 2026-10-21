class MyHashMap {
private:
    struct ListNode{
        int key;
        int value;
        ListNode* next;
        ListNode(int key, int value){
            this->key = key;
            this->value = value;
            next = nullptr;
        }
    };
    
    vector<ListNode*> HashMap;

    int hashFunction(int key){
        return key % HashMap.size();
    }

public:
    MyHashMap() {
        HashMap.resize(10000);
        for(int i=0; i<HashMap.size(); i++){
            HashMap[i] = new ListNode(-1,-1);
        }
    }
    
    void put(int key, int value) {
        ListNode* node = HashMap[hashFunction(key)];
        while(node->next != nullptr){
            if(node->next->key == key){
                node->next->value = value;
                return;
            }
            node = node->next;
        }
        node->next = new ListNode(key,value);
        return;
    }
    
    int get(int key) {
        ListNode* node = HashMap[hashFunction(key)];
        while(node->next != nullptr){
            if(node->next->key == key){
                return node->next->value;
            }
            node = node->next;
        }
        return -1;
    }
    
    void remove(int key) {
        ListNode* node = HashMap[hashFunction(key)];
        while(node->next != nullptr){
            if(node->next->key == key){
                ListNode* temp = node->next;
                node->next = temp->next;
                temp->next = nullptr;
                return;
            }
            node = node->next;
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */