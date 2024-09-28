class Node{
    Node *link[26];
    int end = false;
    public:
    bool isCharExist(char ch){
        return link[ch-'a'];
    }
    Node* getLink(char ch){
        return link[ch-'a'];
    }
    void addNode(char ch){
        Node *nn = new Node();
        link[ch-'a'] = nn;
    }
    void markEnd(){
        end = true;
    }
    void unMarkEnd(){
        end = false;
    }
    bool isEnd(){
        return end;
    }
};
class Trie{
    public:
    Node *root;
    Trie(){
        root = new Node();
    }
    void insert(string &word){
        Node *t = root;
        for(char ch : word){
            if(!t->isCharExist(ch)){
                t->addNode(ch);
            }
            t = t->getLink(ch);
        }
        t->markEnd();
    }
};
void dfs(Node *t,string word, int r, int c, vector<vector<char>> &board, vector<vector<int>> &vis, vector<string> &ans){
        int rows = board.size(), cols = board[0].size();
        vis[r][c] = 1;
        if(t->isEnd()){
            t->unMarkEnd();
            ans.push_back(word);
        }
        if(word.length() == 10){
             vis[r][c] = 0;
            return;
        }
        vector<int> dC={0,0,1,-1}, dR={1,-1,0,0};
        for(int i=0; i<=3; i++){
            int adjR = r + dR[i];
            int adjC = c + dC[i];
            if(adjR >= 0 && adjC >= 0 && adjR < rows && adjC < cols){
                if(!vis[adjR][adjC] && t->isCharExist(board[adjR][adjC])){
                    dfs(t->getLink(board[adjR][adjC]), word + board[adjR][adjC], adjR, adjC, board, vis, ans);
                }
            } 
        }
        vis[r][c] = 0;
    }
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie T;
        Node *rt = T.root;
        int rows = board.size(), cols = board[0].size();
        vector<string> ans;
        for(auto word : words){
            T.insert(word);
        }
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(!rt->isCharExist(board[r][c]))   
                    continue;
                vector<vector<int>> vis(rows, vector<int>(cols,0));
                string word;
                word += board[r][c];
                dfs(rt->getLink(board[r][c]),word,r,c,board,vis,ans);
            }
        }
        return ans;

    }
};