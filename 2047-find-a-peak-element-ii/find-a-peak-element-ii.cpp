class Solution {
    int getRowOfMaxFromColumn(int col, vector<vector<int>> &mat){
        int rows = mat.size(), maxVal = INT_MIN, maxInd = -1;
        for(int r=0; r<rows; r++){
            if(mat[r][col] > maxVal){
                maxVal = mat[r][col];
                maxInd = r;
            }
        }
        return maxInd;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        int l=0, r=cols-1;
        while(l <= r){
            int m = l + (r-l)/2;
            int rowOfMax = getRowOfMaxFromColumn(m, mat);
            if(m-1 >= 0 && mat[rowOfMax][m-1] > mat[rowOfMax][m])
                r = m - 1;
            else if(m+1 < cols && mat[rowOfMax][m+1] > mat[rowOfMax][m])
                l = m + 1;
            else return {rowOfMax,m};
        }
        return {-1,-1};
    }
};