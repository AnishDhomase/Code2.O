class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        set<pair<int,int>> ans;
        for(int i=0; i<rows; i++){
            vector<pair<int,int>> rowComputers;
            for(int j=0; j<cols; j++){
                if(grid[i][j]==1){
                    rowComputers.push_back({i,j});
                }
            }
            if(rowComputers.size() > 1){
                for(auto pr : rowComputers)
                    ans.insert(pr);
            }
        }
        for(int i=0; i<cols; i++){
            vector<pair<int,int>> colComputers;
            for(int j=0; j<rows; j++){
                if(grid[j][i]==1){
                    colComputers.push_back({j,i});
                }
            }
            if(colComputers.size() > 1){
                for(auto pr : colComputers)
                    ans.insert(pr);
            }
        }
        return ans.size();
    }
};