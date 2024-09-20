class Solution {
    bool isValidCoordinate(int y, int x, int rows, int cols){
        return (y >= 0 && x >=0 && x < cols && y < rows);
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int minTime = 0;
        queue<pair<pair<int,int>,int>> Q;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == 2)
                    Q.push({{r,c},0});
            }
        }
        while(Q.size() > 0){
            auto currOrange = Q.front();
            Q.pop();
            int y = currOrange.first.first;
            int x = currOrange.first.second;
            int time = currOrange.second;
            minTime = max(minTime, time);
            vector<int> dY = {0,0,1,-1};
            vector<int> dX = {1,-1,0,0};
            for(int i=0; i<4; i++){
                int adjY = y + dY[i];
                int adjX = x + dX[i];
                if(isValidCoordinate(adjY,adjX,rows,cols) && grid[adjY][adjX] == 1){
                    grid[adjY][adjX] = 2;
                    Q.push({{adjY,adjX},time + 1});
                }
            }
        }
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == 1)
                    return -1;
            }
        }
        return minTime;
    }
};