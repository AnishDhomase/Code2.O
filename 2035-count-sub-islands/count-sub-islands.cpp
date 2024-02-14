class Solution {
    bool isSubIsland (int y, int x, vector<vector<int>> &vis, vector<vector<int>> grid1, vector<vector<int>> grid2){
        bool ans = true;
        int rows = grid2.size(), cols = grid2[0].size();
        queue<pair<int,int>> Q; //{y,x}
        if(grid1[y][x]==1){
            Q.push({y,x});
            vis[y][x]++;
        }
        else    ans = false;
        vector<int> dX = {0,0,1,-1};
        vector<int> dY = {1,-1,0,0};
        while(Q.size()){
            auto curr = Q.front();
            int currY = Q.front().first, currX =  Q.front().second;
            Q.pop();
            for(int i=0; i<4; i++){
                int adjY = currY + dY[i];
                int adjX = currX + dX[i];
                if(0<=adjY && 0<=adjX && adjY<rows && adjX<cols && grid2[adjY][adjX]==1 && !vis[adjY][adjX]){
                    if(ans && grid1[adjY][adjX]!=1)    ans = false;
                    Q.push({adjY,adjX});
                    vis[adjY][adjX]++;
                }
            }
        }
        return ans;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int numIslands = 0;
        int rows = grid2.size(), cols = grid2[0].size();
        vector<vector<int>> vis(rows,vector<int>(cols,0));
        for(int y=0; y<rows; y++){
            for(int x=0; x<cols; x++){
                if(grid2[y][x]==1 && !vis[y][x]){
                    // if(isSubIsland(i,j,vis,grid1,grid2))
                    bool ans = true;
                    queue<pair<int,int>> Q; //{y,x}
                    if(grid1[y][x]==1){
                        Q.push({y,x});
                        vis[y][x]++;
                    }
                    else    ans = false;
                    vector<int> dX = {0,0,1,-1};
                    vector<int> dY = {1,-1,0,0};
                    while(Q.size()){
                        auto curr = Q.front();
                        int currY = Q.front().first, currX =  Q.front().second;
                        Q.pop();
                        for(int i=0; i<4; i++){
                            int adjY = currY + dY[i];
                            int adjX = currX + dX[i];
                            if(0<=adjY && 0<=adjX && adjY<rows && adjX<cols && grid2[adjY][adjX]==1 && !vis[adjY][adjX]){
                                if(ans && grid1[adjY][adjX]!=1)    ans = false;
                                Q.push({adjY,adjX});
                                vis[adjY][adjX]++;
                            }
                        }
                    }
                    if(ans)
                        numIslands++;
                }
            }
        }
        return numIslands;
    }
};