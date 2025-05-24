class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap; //{dist,y,x}
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = grid[0][0];
        minHeap.push({dist[0][0], 0, 0});
        vector<int> dC = {0, 0, 1, -1};
        vector<int> dR = {1, -1, 0, 0};
        while(minHeap.size() > 0){
            auto currNode = minHeap.top();
            int currdist = currNode[0], r = currNode[1], c = currNode[2];
            minHeap.pop();
            for(int i=0; i<4; i++){
                int adjR = r + dR[i];
                int adjC = c + dC[i];
                if(adjC >= 0 && adjC < n && adjR >= 0 && adjR < n){
                    int distToReachAdj = max(currdist, grid[adjR][adjC]);
                    if(distToReachAdj < dist[adjR][adjC]){
                        dist[adjR][adjC] = distToReachAdj;
                        minHeap.push({distToReachAdj, adjR, adjC});
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};