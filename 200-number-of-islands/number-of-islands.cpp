class Solution {
    void bfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> grid){
        int row = grid.size(), col = grid[0].size();
        queue<pair<int,int>> Q;
        vector<int> dX = {0,0,1,-1};
        vector<int> dY = {1,-1,0,0};
        Q.push({r,c});
        vis[r][c]++;
        while(Q.size()){
            auto node = Q.front();
            Q.pop();
            int y = node.first, x = node.second;
            for(int i=0; i<4; i++){
                int adjR = y + dY[i];
                int adjC = x + dX[i];
                if(0<=adjR && adjR<row && 0<=adjC && adjC<col && grid[adjR][adjC]=='1'){
                    if(!vis[adjR][adjC]){
                        Q.push({adjR,adjC});
                        vis[adjR][adjC]++;
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size(), ans=0;
        vector<vector<int>> vis(row, vector<int>(col,0));
        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(grid[r][c]=='1' && !vis[r][c]){
                    ans++;
                    bfs(r, c, vis, grid);
                }
            }
        }
        return ans;

    }
};