class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int top=0, bottom=matrix.size()-1, left=0, right=matrix[0].size()-1;
        int r=0, c;
        while(top<=bottom && left<=right){
            for(c=left; c<=right; c++)
                ans.push_back(matrix[r][c]);
            top++; 
            c--;

            if(top > bottom)    break;
            for(r=top; r<=bottom; r++)
                ans.push_back(matrix[r][c]);
            right--; 
            r--;

            if(left > right)    break;
            for(c=right; c>=left; c--)
                ans.push_back(matrix[r][c]);
            bottom--; 
            c++;

            if(top > bottom)    break;
            for(r=bottom; r>=top; r--)
                ans.push_back(matrix[r][c]);
            left++; 
            r++;
        }
        return ans;
        // vector<int> ans;
        // int switchInc_Dec = 0;
        // bool colChange = true, increment = true;
        // int r=0, c=0, rows=matrix.size(), cols=matrix[0].size();
        // int topRowCovered = -1, bottomRowCovered = rows;
        // int leftColCovered = -1, RightColCovered = cols;
        // ans.push_back(matrix[0][0]);
        // while((topRowCovered+1 < bottomRowCovered) && (leftColCovered+1 < RightColCovered)){
        //     if(increment){
        //         if(colChange){
        //             while(c+1 < RightColCovered){
        //                 c++;
        //                 ans.push_back(matrix[r][c]);
        //             }
        //             topRowCovered ++;
        //         }
        //         else{
        //             while(r+1 < bottomRowCovered){
        //                 r++;
        //                 ans.push_back(matrix[r][c]);
        //             }
        //             RightColCovered--;
        //         }
        //     }
        //     else{
        //         if(colChange){
        //             while(c-1 > leftColCovered){
        //                 c--;
        //                 ans.push_back(matrix[r][c]);
        //             }
        //             bottomRowCovered --;
        //         }
        //         else{
        //             while(r-1 > topRowCovered){
        //                 r--;
        //                 ans.push_back(matrix[r][c]);
        //             }
        //             leftColCovered ++;
        //         }    
        //     }  
        //     switchInc_Dec++;
        //     if(switchInc_Dec % 2 == 0)
        //         increment = ! increment;
        //     colChange = ! colChange;      
        // }
        // return ans;
    }
};