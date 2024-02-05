class Solution {
    int bfs(int y, int x, vector<vector<int>> &vis, vector<vector<int>> grid){
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int,int>> q; //{y,x}
        int sz = 0;
        q.push({y,x});
        vis[y][x]++;
        vector<int> dY = {1,-1,0,0};
        vector<int> dX = {0,0,1,-1};
        while(q.size()){
            int nodeY = q.front().first, nodeX = q.front().second;
            q.pop();
            sz++;
            for(int i=0; i<4; i++){
                int adjY = nodeY + dY[i];
                int adjX = nodeX + dX[i];
                if(0 <= adjY && 0 <= adjX && adjY < rows && adjX < cols){
                    if(grid[adjY][adjX] && !vis[adjY][adjX]){
                        vis[adjY][adjX]++;
                        q.push({adjY,adjX});
                    }
                }
            }
        }
        return sz;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSz = 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        for(int y=0; y<rows; y++){
            for(int x=0; x<cols; x++){
                if(grid[y][x] && !vis[y][x]){
                    int islandSz = bfs(y, x, vis, grid);
                    maxSz = islandSz > maxSz ? islandSz : maxSz;
                }
            }
        }
        return maxSz;
        
    }
};