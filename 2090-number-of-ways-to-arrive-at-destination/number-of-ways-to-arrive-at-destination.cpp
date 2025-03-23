typedef long long LL;
class Solution {
    int mod = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<LL> minDist(n, 1e12);
        vector<LL> waysWithMinDist(n, 0);
        waysWithMinDist[0] = 1;
        minDist[0] = 0;
        vector<vector<pair<int,LL>>> adjList(n);
        for(auto road: roads){
            int u = road[0], v = road[1], wt = road[2];
            adjList[u].push_back({v, wt}); 
            adjList[v].push_back({u, wt});
        }
        // bfs
        priority_queue<pair<LL,int>, vector<pair<LL, int>>, greater<pair<LL, int>>> q; //{dist,node}
        q.push({0,0});
        while(q.size() > 0){
            auto top = q.top();
            q.pop();

            int node = top.second;
            LL dist = top.first;
            for(auto adj: adjList[node]){
                int adjNode = adj.first;
                LL distToReach = adj.second;
                LL newDist = dist + distToReach;
                if(newDist < minDist[adjNode]){
                    minDist[adjNode] = newDist;
                    waysWithMinDist[adjNode] = waysWithMinDist[node];
                    q.push({newDist, adjNode});
                }
                else if(newDist == minDist[adjNode]){
                    waysWithMinDist[adjNode] = ((LL) waysWithMinDist[adjNode] + waysWithMinDist[node]) % mod;
                }
            }


        }
        return waysWithMinDist[n-1];
    }
};