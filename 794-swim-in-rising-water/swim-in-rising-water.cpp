class Solution {
    int getMaxValueInGrid(vector<vector<int>>& grid){
        int maxElem = INT_MIN;
        for(auto row: grid){
            int rowMax = *max_element(row.begin(), row.end());
            maxElem = max(maxElem, rowMax);
        }
        return maxElem;
    }
    bool isPossibleToReachTargetCell(int time, vector<vector<int>>& grid){
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int,int>> Q;
        if(grid[0][0] <= time){
            Q.push({0, 0});
            vis[0][0] = 1;
        }
        vector<int> dC = {0, 0, 1, -1};
        vector<int> dR = {1, -1, 0, 0};
        while(Q.size() > 0){
            auto currNode = Q.front();
            int r = currNode.first, c = currNode.second;
            Q.pop();
            for(int i=0; i<4; i++){
                int adjR = r + dR[i];
                int adjC = c + dC[i];
                if(adjC >= 0 && adjC < n && adjR >= 0 && adjR < n){
                    if(grid[adjR][adjC] <= time && !vis[adjR][adjC]){
                        vis[adjR][adjC] = 1;
                        Q.push({adjR, adjC});
                    }
                }
            }
        }
        return vis[n-1][n-1];
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int low = 0, high = getMaxValueInGrid(grid), ans = high;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossibleToReachTargetCell(mid, grid)){
                ans = mid;
                high = mid - 1;
            }
            else    low = mid + 1;
        }
        return ans;
    }
};