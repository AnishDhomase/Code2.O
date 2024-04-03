class Solution {
    bool canFormWord(int ind, int r, int c, string &word, vector<vector<char>> &board){
        int rows = board.size(), cols = board[0].size();
        if(ind == word.length())
            return true;
        if(0>r || 0>c || r>=rows || c>=cols)
            return false;
        if(word[ind] != board[r][c])
            return false;
        char prevrc = board[r][c];
        board[r][c] = '0';
        vector<int> dX = {0,0,-1,1};
        vector<int> dY = {1,-1,0,0};
        for(int i=0; i<4; i++){
            int adjR = r + dY[i];
            int adjC = c + dX[i];
            if(canFormWord(ind+1, adjR, adjC, word, board))
                return true;
        }
        board[r][c] = prevrc;
        return false;
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        if(rows * cols < word.length())   return false;
        unordered_map<char,int> freq;
        for(auto ch : word) freq[ch]++;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                freq[board[r][c]]--;
            }
        }
        for(auto it : freq){
            if(it.second > 0)
                return false;
        }
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(canFormWord(0, r, c, word, board))
                    return true;
            }
        }
        return false;
    }
};