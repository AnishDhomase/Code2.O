class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] !=0 || grid[n-1][n-1] !=0)
            return -1;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>> minHp;
        minHp.push({1,{0,0}});
        dist[0][0] = 1;
        while(minHp.size() > 0){
            auto curr = minHp.front();
            minHp.pop();
            int y = curr.second.first;
            int x = curr.second.second;
            int currDist = curr.first;
            for(int dX=-1; dX<=1; dX++){
                for(int dY=-1; dY<=1; dY++){
                    if(dX==dY && dX==0) continue;
                    int adjX = dX + x;
                    int adjY = dY + y;
                    if(adjX >= 0 && adjY >= 0 && adjX < n && adjY < n){
                        if(grid[adjY][adjX] == 0){
                            int newDist = currDist + 1;
                            if(newDist < dist[adjY][adjX]){
                                dist[adjY][adjX] = newDist;
                                minHp.push({newDist,{adjY,adjX}});
                            }
                        }
                    }
                }
            }
        }
        if(dist[n-1][n-1] == 1e9) return -1;
        return dist[n-1][n-1];

    }
};