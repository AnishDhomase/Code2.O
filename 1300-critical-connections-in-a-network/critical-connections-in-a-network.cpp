class Solution {
    void dfs(int node, int par, vector<vector<int>> &bridges, int &timer, vector<int> &time, vector<int> &low, vector<int> &vis, vector<vector<int>> &adjList){
        vis[node] = 1;
        time[node] = low[node] = timer;
        timer ++;
        for(auto adjNode : adjList[node]){
            if(adjNode == par)  continue;
            if(vis[adjNode] == 0){
                dfs(adjNode, node, bridges, timer, time, low, vis, adjList);
                low[node] = min(low[node], low[adjNode]);
                if(time[node] < low[adjNode]){
                    bridges.push_back({node, adjNode});
                }
            }
            else low[node] = min(low[node], low[adjNode]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n);
        for(auto c : connections){
            adjList[c[0]].push_back(c[1]);
            adjList[c[1]].push_back(c[0]);
        }
        vector<int> time(n), low(n), vis(n,0);
        vector<vector<int>> bridges;
        int timer = 1;
        dfs(0, -1, bridges, timer, time, low, vis, adjList);
        return bridges;
    }
};