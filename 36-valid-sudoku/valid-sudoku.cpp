class Solution {
    int getBoxNumber(int r, int c){
        return ( r / 3 * 3) + (c / 3);
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> freqRow(9, vector<int>(9, 0));
        vector<vector<int>> freqCol(9, vector<int>(9, 0));
        vector<vector<int>> freqBox(9, vector<int>(9, 0));

        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                char value = board[r][c];
                if(value == '.')    continue;

                freqRow[r][value-'1'] ++;
                if(freqRow[r][value-'1'] == 2)  return false;

                freqCol[c][value-'1'] ++;
                if(freqCol[c][value-'1'] == 2)  return false;

                int box = getBoxNumber(r, c);
                freqBox[box][value-'1'] ++;
                if(freqBox[box][value-'1'] == 2)  return false;
            }     
        }
        return true;
    }
};