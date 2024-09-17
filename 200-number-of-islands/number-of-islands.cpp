class Solution {
    void bfs(int r, int c, vector<vector<bool>> &vis, vector<vector<char>> &grid){
        int rows= grid.size(), cols = grid[0].size();

        // init config
        vis[r][c] = true;
        queue<pair<int,int>> Q;
        Q.push({r,c});

        // trav
        vector<int> dY = {1, -1, 0, 0};
        vector<int> dX = {0, 0, 1, -1};
        while(Q.size() > 0){
            auto currNode = Q.front();
            int currY = currNode.first, currX = currNode.second;
            Q.pop();
            for(int i=0; i<4; i++){
                int adjY = currY + dY[i];
                int adjX = currX + dX[i];
                if(0 <= adjX && adjX < cols && 0 <= adjY && adjY < rows){
                    if(grid[adjY][adjX] == '1' && !vis[adjY][adjX]){
                        vis[adjY][adjX] = true;
                        Q.push({adjY,adjX});
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows= grid.size(), cols = grid[0].size(), cnt = 0;
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == '1' && !vis[r][c]){
                    bfs(r, c, vis, grid);
                    cnt ++;
                }
            }
        }
        return cnt;
        
    }
};