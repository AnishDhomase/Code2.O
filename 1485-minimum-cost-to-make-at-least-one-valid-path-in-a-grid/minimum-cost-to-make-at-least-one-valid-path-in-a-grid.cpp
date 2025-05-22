class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, 1e9));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap; //{dist, y, x}
        minHeap.push({0,0,0});
        dist[0][0] = 0;
        vector<int> dR = {0,0,1,-1};
        vector<int> dC = {1,-1,0,0};
        while(minHeap.size() > 0){
            auto currNode = minHeap.top();
            int currDist = currNode[0], r = currNode[1], c = currNode[2];
            minHeap.pop();
            for(int i=0; i<4; i++){
                int adjC = c + dC[i];
                int adjR = r + dR[i];
                if(adjC >= 0 && adjR >= 0 && adjC < cols && adjR < rows){
                    int adjDist = ((i+1) != grid[r][c]) ? 1 : 0;
                    if((currDist + adjDist) < dist[adjR][adjC]){
                        minHeap.push({currDist + adjDist, adjR, adjC});
                        dist[adjR][adjC] = currDist + adjDist;
                    }
                }
            }
        }
        return dist[rows-1][cols-1];


    }
};