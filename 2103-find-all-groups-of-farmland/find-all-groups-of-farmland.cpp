class Solution {
    void bfs(int &i, int &j, vector<vector<int>> &ans, vector<vector<int>> land, vector<vector<int>> &vis){
        int rows = land.size(), cols = land[0].size();
        int br=i, bc=j;
        for(int c=j+1; c<cols; c++){
            if(land[i][c])  bc = c;
            else    break;             
        }
        for(int r=i+1; r<rows; r++){
            if(land[r][j])  br = r;
            else    break;             
        }
        ans.push_back({i,j,br,bc});
        for(int p=i; p<=br; p++){
            for(int q=j; q<=bc; q++){
                vis[p][q]++;
            }
        }
        j = bc;
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int rows = land.size(), cols = land[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols,0));
        vector<vector<int>> ans;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(land[i][j] && !vis[i][j]){
                    int br=i, bc=j;
                    for(int c=j+1; c<cols; c++){
                        if(land[i][c])  bc = c;
                        else    break;             
                    }
                    for(int r=i+1; r<rows; r++){
                        if(land[r][j])  br = r;
                        else    break;             
                    }
                    ans.push_back({i,j,br,bc});
                    for(int p=i; p<=br; p++){
                        for(int q=j; q<=bc; q++){
                            vis[p][q]++;
                        }
                    }
                    j = bc;
                    // bfs(i,j,ans,land,vis);
                }
            }
        }
        return ans;
    }
};