class Node{
    Node *link[2];
    public:
    bool isBitExist(int bit){
        return link[bit];
    }
    Node* getLink(int bit){
        return link[bit];
    }
    void addNode(int bit){
        Node *nn = new Node();
        link[bit] = nn;
    }
};
class Trie {
    Node *root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int n){
        Node *t = root;
        for(int i=31; i>=0; i--){
            int bit = n & 1<<i ? 1 : 0;
            if(!t->isBitExist(bit))
                t->addNode(bit);
            t = t->getLink(bit);
        }
    }
    int getMaxXor(int x){
        Node *t = root;
        int xr = 0;
        for(int i=31; i>=0; i--){
            int bit = x & 1<<i ? 1 : 0;
            if(t->isBitExist(!bit)){
                xr += 1<<i;
                t = t->getLink(!bit);
            }
            else{
                t = t->getLink(bit);
            }
        }
        return xr;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie T;
        int n = queries.size(), sz = nums.size();
        vector<vector<int>> queries1;
        vector<int> ans(n,-1);
        int i=0;
        for(auto q : queries){
            queries1.push_back({q[1], q[0], i});
            i ++;
        }
        sort(nums.begin(), nums.end());
        sort(queries1.begin(), queries1.end());
        i = 0;
        for(auto q : queries1){
            int m = q[0], x = q[1], ind = q[2];
            while(i < sz && nums[i] <= m){
                T.insert(nums[i]);
                i ++;
            }
            if(i != 0)
                ans[ind] = T.getMaxXor(x);
        }
        return ans;
    }
};