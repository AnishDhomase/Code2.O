class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> eff(rows, vector<int>(cols,1e9));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> minHp;
        eff[0][0] = 0;
        minHp.push({0, {0,0}}); //{eff,{y,x}}
        while(minHp.size()){
            auto currNode = minHp.top();
            minHp.pop();
            int effort = currNode.first;
            int y = currNode.second.first, x = currNode.second.second;
            if(effort > eff[y][x])
                continue;
            vector<int> dX = {0,0,-1,1}, dY = {1,-1,0,0};
            for(int i=0; i<4; i++){
                int adjX = x + dX[i];
                int adjY = y + dY[i];
                if(adjX >= 0 && adjY >= 0 && adjY < rows && adjX < cols){
                    int adjEff = abs(heights[adjY][adjX] - heights[y][x]);
                    if(eff[adjY][adjX] == 1e9){
                        eff[adjY][adjX] = max(effort, adjEff);
                        minHp.push({eff[adjY][adjX], {adjY,adjX}});
                    }
                    else{
                        if(eff[adjY][adjX] > max(effort, adjEff)){
                            eff[adjY][adjX] = max(effort, adjEff);
                            minHp.push({eff[adjY][adjX], {adjY,adjX}});
                        }
                    }
                }
            }
        }
        return eff[rows-1][cols-1];        
    }
};