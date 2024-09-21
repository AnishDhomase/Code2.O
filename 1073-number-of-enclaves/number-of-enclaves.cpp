class Solution {
    void bfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis){
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int,int>> Q;
        Q.push({r,c});
        vis[r][c] = 1;
        while(Q.size() > 0){
            auto currNode = Q.front();
            Q.pop();
            int currY = currNode.first, currX = currNode.second;
            vector<int> dY = {0,0,-1,1}, dX = {1,-1,0,0};
            for(int i=0; i<4; i++){
                int adjX = currX + dX[i];
                int adjY = currY + dY[i];
                if(adjX >= 0 && adjY >= 0 && adjX < cols && adjY < rows){
                    if(grid[adjY][adjX] == 1 && !vis[adjY][adjX]){
                        vis[adjY][adjX] = 1;
                        Q.push({adjY,adjX});
                    }
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), cnt = 0;
        vector<vector<int>> vis(rows, vector<int> (cols,0));
        for(int i=0; i<rows; i++){
            if(!vis[i][0] && grid[i][0] == 1){
                bfs(i,0,grid,vis);
            }  
            if(!vis[i][cols-1] && grid[i][cols-1] == 1){
                bfs(i,cols-1,grid,vis);
            }    
        }
        for(int i=1; i<cols-1; i++){
            if(!vis[0][i] && grid[0][i] == 1){
                bfs(0,i,grid,vis);
            }  
            if(!vis[rows-1][i] && grid[rows-1][i] == 1){
                bfs(rows-1,i,grid,vis);
            }    
        }
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == 1 && !vis[r][c])
                    cnt ++;
            }
        }
        return cnt;
    }
};