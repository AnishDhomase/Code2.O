class Solution {
    int maxIn3by3(int r, int c, vector<vector<int>> &grid){
        int max3by3 = INT_MIN;
        for(int i=r; i<r+3; i++){
            for(int j=c; j<c+3; j++){
                max3by3 = max(max3by3, grid[i][j]);
            }
        }
        return max3by3;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2));
        for(int r=0; r<n-2; r++){
            for(int c=0; c<n-2; c++){
                ans[r][c] = maxIn3by3(r, c, grid);
            }
        }
        return ans;
    }
};