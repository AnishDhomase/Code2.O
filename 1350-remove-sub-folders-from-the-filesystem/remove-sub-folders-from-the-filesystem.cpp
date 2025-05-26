struct TrieNode{
    map<string, TrieNode*> mp;
    bool flag;
    TrieNode(){
        flag = false;
    }
    bool isStringExist(string &str){
        return mp[str] != NULL;
    }
    void createTrieNodeForStr(string &str){
        TrieNode *nn = new TrieNode();
        mp[str] = nn;
    }
    TrieNode* getLinkForStr(string &str){
        return mp[str];
    }
    bool isStrEnd(){
        return flag;
    }
    void markStrEnd(){
        flag = true;
    }
};
class Trie{
    TrieNode *root;
    public:
    Trie(){
        root = new TrieNode();
    }
    bool insertTrieNode(string ioPath){
        string path = ioPath + '/';
        TrieNode *it = root;
        string str;
        if(it->isStrEnd())  return false;
        for(int i=1; i<path.length(); i++){
            if(path[i] != '/'){
                str += path[i];
                continue;
            }   
            if(!it->isStringExist(str))
                it->createTrieNodeForStr(str);
            it = it->getLinkForStr(str);
            if(it->isStrEnd())  return false;
            str = "";
        }
        it->markStrEnd();
        return true;
    }
};
bool compByLenIncreasingOrder(string &s1, string &s2){
    return s1.length() < s2.length();
}
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        Trie T;
        sort(folder.begin(), folder.end(), compByLenIncreasingOrder);
        for(auto path: folder){
            if(T.insertTrieNode(path))
                ans.push_back(path);
        }
        return ans;
    }
};