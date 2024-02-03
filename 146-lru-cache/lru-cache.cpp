struct node{
    pair<int,int> pr;
    node *prev, *next;
    node(pair<int,int> p){
        pr = p;
        prev = next = NULL;
    }
};

class LRUCache {
    map<int,node*> mp;
    node *head, *tail;
    int cap;
    void del(node *n){
        if(head==n){
            head = head->next;
            if(head)
                head->prev = NULL;
            else
                tail = NULL;
        }
        else if(tail==n){
            n->prev->next = NULL;
            tail = n->prev;
        }
        else{
            n->prev->next = n->next;
            n->next->prev = n->prev;
        }
        delete(n);
    }
    void insertAtEnd(node *nn){ 
        if(tail){
            tail->next = nn;
            nn->prev = tail;
            tail = nn;
        }
        else{
            head = tail = nn;
        }
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = tail = NULL;
    }
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        int ans = (mp[key]->pr).second;
        del(mp[key]);
        node *nn = new node({key,ans});
        insertAtEnd(nn);
        mp.erase(key);
        mp[key]=nn;
        return ans;
    }
    void put(int key, int value) {
        node *nn = new node({key,value});
        if(mp.find(key) != mp.end()){
            //means update
            del(mp[key]);
            insertAtEnd(nn);
            mp[key] = nn;
        }
        else{
            if(mp.size() == cap){
                //no space
                mp.erase((head->pr).first);
                del(head);
                mp[key]=nn;
                insertAtEnd(nn);
            }
            else{
                //is space
                mp[key]=nn;
                insertAtEnd(nn);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */