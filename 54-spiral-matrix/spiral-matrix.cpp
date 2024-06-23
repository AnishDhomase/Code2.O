class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int switchInc_Dec = 0;
        bool colChange = true, increment = true;
        int r=0, c=0, rows=matrix.size(), cols=matrix[0].size();
        ans.push_back(matrix[0][0]);
        vector<int> rowCovered(rows,0), colCovered(cols,0);
        while(true){
            if(increment){
                if(colChange){
                    while(c+1<cols && !colCovered[c+1]){
                        c++;
                        ans.push_back(matrix[r][c]);
                    }
                    rowCovered[r] = 1;
                    if(r+1==rows || rowCovered[r+1]) break;
                    switchInc_Dec++;
                    if(switchInc_Dec % 2 == 0)
                        increment = ! increment;
                    colChange = ! colChange;
                }
                else{
                    while(r+1<rows && !rowCovered[r+1]){
                        r++;
                        ans.push_back(matrix[r][c]);
                    }
                    colCovered[c] = 1;
                    if(c-1<0 || colCovered[c-1]) break;
                    switchInc_Dec++;
                    if(switchInc_Dec % 2 == 0)
                        increment = ! increment;
                    colChange = ! colChange;
                }
            }
            else{
                if(colChange){
                    while(c-1>=0 && !colCovered[c-1]){
                        c--;
                        ans.push_back(matrix[r][c]);
                    }
                    rowCovered[r] = 1;
                    if(r-1<0 || rowCovered[r-1]) break;
                    switchInc_Dec++;
                    if(switchInc_Dec % 2 == 0)
                        increment = ! increment;
                    colChange = ! colChange;
                }
                else{
                    while(r-1>=0 && !rowCovered[r-1]){
                        r--;
                        ans.push_back(matrix[r][c]);
                    }
                    colCovered[c] = 1;
                    if(c+1==cols || colCovered[c+1]) break;
                    switchInc_Dec++;
                    if(switchInc_Dec % 2 == 0)
                        increment = ! increment;
                    colChange = ! colChange;
                }
            }        
        }
        return ans;
    }
};