class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols,0));
        set<int> sortedQueries(queries.begin(), queries.end());
        queue<pair<int,int>> Q1, Q2;
        unordered_map<int,int> mp; //query -> ans
        vector<int> ans;
        vector<int> dX = {0, 0, 1, -1};
        vector<int> dY = {1, -1, 0, 0};

        Q1.push({0,0});
        vis[0][0] ++;
        int cnt = 0;
        for(auto query: sortedQueries){
            while(Q1.size() > 0){
                int y = Q1.front().first, x = Q1.front().second;
                Q1.pop();
                if(query > grid[y][x]){
                    cnt ++;
                    for(int i=0; i<4; i++){
                        int adjX = x + dX[i];
                        int adjY = y + dY[i];
                        if(adjX < cols && adjY < rows && adjX >= 0 && adjY >= 0){
                            if(!vis[adjY][adjX]){
                                vis[adjY][adjX] = 1;
                                Q1.push({adjY,adjX}); 
                            }
                        }    
                    }
                }
                else Q2.push({y,x});   
            }
            mp[query] = cnt;          
            while(Q2.size() > 0){
                Q1.push(Q2.front());
                Q2.pop();   
            }
        }
        for(auto query: queries)
            ans.push_back(mp[query]);
        return ans;
        
    }
};