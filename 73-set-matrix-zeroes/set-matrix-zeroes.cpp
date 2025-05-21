class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size(); 
        vector<int> rowMarker(rows, 0);
        vector<int> colMarker(cols, 0);
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(matrix[r][c] == 0){
                    rowMarker[r] = 1;
                    colMarker[c] = 1;
                }
            }
        }
        for(int r=0; r<rows; r++){
            if(rowMarker[r] == 1){
                for(int c=0; c<cols; c++)
                    matrix[r][c] = 0;
            }
        }
        for(int c=0; c<cols; c++){
            if(colMarker[c] == 1){
                for(int r=0; r<rows; r++)
                    matrix[r][c] = 0;
            }
        }
    }
};