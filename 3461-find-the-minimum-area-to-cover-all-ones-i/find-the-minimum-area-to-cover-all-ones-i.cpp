class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        pair<int,int> x, y; //{min, max}
        x = {cols, -1}; 
        y = {rows, -1}; 
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == 1){
                    x.first = min(x.first, c);
                    x.second = max(x.second, c);
                    y.first = min(y.first, r);
                    y.second = max(y.second, r);
                }
            }
        }
        int verticleSide = x.second - x.first + 1;
        int horizontalSide = y.second - y.first + 1;
        int area = verticleSide * horizontalSide;
        return area;
    }
};