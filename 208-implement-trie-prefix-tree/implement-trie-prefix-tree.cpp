struct Node {
    Node *link[26];
    bool flag = false;
    bool isCharExists(char ch){
        return link[ch-'a'] != NULL;
    }
    void addNewNodeForChar(char ch){
        Node *nn = new Node();
        link[ch-'a'] = nn;
    }   
    Node* getLinkForChar(char ch){
        return link[ch-'a'];
    }
    void markEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *t = root;
        for(auto ch : word){
            if(! t->isCharExists(ch)){
                
                t->addNewNodeForChar(ch);
            }
            t = t->getLinkForChar(ch);
        }
        t->markEnd();
    }
    
    bool search(string word) {
        Node *t = root;
        for(auto ch: word){
            if(! t->isCharExists(ch))
                return false;
            t = t->getLinkForChar(ch);
        }
        return t->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *t = root;
        for(auto ch: prefix){
            if(! t->isCharExists(ch))
                return false;
            t = t->getLinkForChar(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */