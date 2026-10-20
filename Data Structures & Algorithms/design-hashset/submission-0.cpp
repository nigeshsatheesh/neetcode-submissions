class MyHashSet {
private:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int val){
            this->val = val;
            next = nullptr;
        }
    };
    vector<ListNode*> HashSet;

    int hashFunction(int key){
        return key % HashSet.size();
    }
public:
    MyHashSet(){
        HashSet.resize(10000);
        for(int i=0; i<HashSet.size(); i++){
            HashSet[i] = new ListNode(-1);
        }
    }
    
    void add(int key) {
        ListNode* node = HashSet[hashFunction(key)];
        while(node->next != nullptr){
            if(node->next->val == key){
                return;
            }
            node = node->next;
        }
        node->next = new ListNode(key);
    }
    
    void remove(int key) {
        ListNode* node = HashSet[hashFunction(key)];
        while(node->next != nullptr){
            if(node->next->val == key){
                ListNode* temp = node->next;
                node->next = temp->next;
                temp->next = nullptr;
                return;
            }
            node = node->next;
        }
    }
    
    bool contains(int key) {
        ListNode* node = HashSet[hashFunction(key)];
        while(node != nullptr){
            if(node->val == key){
                return true;
            }
            node = node->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */