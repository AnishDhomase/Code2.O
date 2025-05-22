class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, 1e9));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap; //{dist, x, y}
        minHeap.push({0,0,0});
        dist[0][0] = 0;
        vector<int> dC = {0,0,1,-1};
        vector<int> dR = {1,-1,0,0};
        while(minHeap.size() > 0){
            auto currNode = minHeap.top();
            int currDist = currNode[0], c = currNode[1], r = currNode[2];
            minHeap.pop();
            for(int i=0; i<4; i++){
                int adjC = c + dC[i];
                int adjR = r + dR[i];
                if(adjC >= 0 && adjC < cols && adjR >= 0 && adjR < rows){
                    int adjDist = grid[adjR][adjC];
                    if(currDist + adjDist < dist[adjR][adjC]){
                        minHeap.push({currDist + adjDist, adjC, adjR});
                        dist[adjR][adjC] = currDist + adjDist;
                    }
                }
            }
        }
        return dist[rows-1][cols-1];

    }
};