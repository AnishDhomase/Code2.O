class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = (int)(1e9+7);
        vector<vector<pair<int,int>>> adjList(n, vector<pair<int,int>>(0));
        vector<int> ways(n,0);
        vector<long long> dist(n,1e12);
        priority_queue<pair<long long, int>,vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        for(auto r : roads){
            adjList[r[0]].push_back({r[1],r[2]});
            adjList[r[1]].push_back({r[0],r[2]});
        }
        ways[0] = 1;
        dist[0] = 0;
        pq.push({0,0});
        while(pq.size()){
            auto top = pq.top(); 
            pq.pop();
            long long distTillNode = top.first;
            int node = top.second;
            int waysToNode = ways[node];
            for(auto adj : adjList[node]){
                int adjNode = adj.first;
                long long adjDist = adj.second;
                if(distTillNode + adjDist < dist[adjNode]){
                    pq.push({distTillNode + adjDist, adjNode});
                    dist[adjNode] = distTillNode + adjDist;
                    ways[adjNode] = waysToNode;
                }
                else if(distTillNode + adjDist == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + waysToNode) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};