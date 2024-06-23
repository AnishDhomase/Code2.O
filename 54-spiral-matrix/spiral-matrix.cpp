class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int switchInc_Dec = 0;
        bool colChange = true, increment = true;
        int r=0, c=0, rows=matrix.size(), cols=matrix[0].size();
        int topRowCovered = -1, bottomRowCovered = rows;
        int leftColCovered = -1, RightColCovered = cols;
        ans.push_back(matrix[0][0]);
        while((topRowCovered+1 < bottomRowCovered) && (leftColCovered+1 < RightColCovered)){
            if(increment){
                if(colChange){
                    while(c+1 < RightColCovered){
                        c++;
                        ans.push_back(matrix[r][c]);
                    }
                    topRowCovered ++;
                }
                else{
                    while(r+1 < bottomRowCovered){
                        r++;
                        ans.push_back(matrix[r][c]);
                    }
                    RightColCovered--;
                }
            }
            else{
                if(colChange){
                    while(c-1 > leftColCovered){
                        c--;
                        ans.push_back(matrix[r][c]);
                    }
                    bottomRowCovered --;
                }
                else{
                    while(r-1 > topRowCovered){
                        r--;
                        ans.push_back(matrix[r][c]);
                    }
                    leftColCovered ++;
                }    
            }  
            switchInc_Dec++;
            if(switchInc_Dec % 2 == 0)
                increment = ! increment;
            colChange = ! colChange;      
        }
        return ans;
    }
};