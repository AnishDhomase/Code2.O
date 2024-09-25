class Node{
    Node *link[26];
    int prefixCnt = 0;
public:
    bool isCharExist(char ch){
        return link[ch-'a'] != NULL;
    }
    void addNode(char ch){
        Node *nn = new Node();
        link[ch-'a'] = nn;
    }
    Node* getLink(char ch){
        return link[ch-'a'];
    }
    int getPrefixCnt(){
        return prefixCnt;
    }
    void incPrefixCnt(){
        prefixCnt ++;
    }
};

class Trie{
    Node *root;
public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node *t = root;
        for(auto ch : word){
            if(!t->isCharExist(ch)){
                t->addNode(ch);
            }
            t = t->getLink(ch);
            t->incPrefixCnt();
        }
    }
    int countOfSubstringPrefix(string word){
        int cnt = 0;
        Node *t = root;
        for(auto ch : word){
            t = t->getLink(ch);
            cnt += t->getPrefixCnt();
        }
        return cnt;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        Trie T;
        for(auto word : words)
            T.insert(word);
        for(auto word : words){
            int cnt = T.countOfSubstringPrefix(word);
            ans.push_back(cnt);
        }
        return ans;
    }
};