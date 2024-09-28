class Node{
    Node *link[2];
    public:
    bool isBitExist(int bit){
        return link[bit] != NULL;
    }
    Node* getlink(int bit){
        return link[bit];
    }
    void addNode(int bit){
        Node *nn = new Node();
        link[bit] = nn;
    }
};
class Trie{ 
    Node *root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int n){
        Node *t = root;
        for(int i=31; i>=0; i--){
            int bit = (n & (1<<i)) ? 1 : 0;
            if(! t->isBitExist(bit)){
                t->addNode(bit);
            }
            t = t->getlink(bit);
        }
    }
    int getMaxXor(int n){
        Node *t = root;
        int xr = 0;
        for(int i=31; i>=0; i--){
            int bit = (n & (1<<i)) ? 1 : 0;
            if(t->isBitExist(!bit)){
                xr += (1<<i);
                t = t->getlink(!bit);
            }
            else{
                t = t->getlink(bit);
            } 
        }
        return xr;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxXor = 0;
        Trie T;
        for(int num : nums)
            T.insert(num);
        
        for(int num : nums){
            int xr = T.getMaxXor(num);
            maxXor = max(maxXor,xr);
        }
        return maxXor;
    }
};