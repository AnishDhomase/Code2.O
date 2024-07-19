class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> rowMin(rows, vector<int>(0));
        vector<int> colMax(cols, -1), ans;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                colMax[c] = max(colMax[c], matrix[r][c]);
                if(!rowMin[r].size() || matrix[r][c] == matrix[r][rowMin[r][0]]){
                    rowMin[r].push_back(c);
                }
                else if(matrix[r][c] < matrix[r][rowMin[r][0]]){
                    rowMin[r].clear();
                    rowMin[r].push_back(c);
                }
            }
        }
        for(int r=0; r<rows; r++){
            for(auto c: rowMin[r]){
                int minValOfRow = matrix[r][c];
                if(minValOfRow == colMax[c])
                    ans.push_back(minValOfRow);
            }
        }
        return ans;
    }
};