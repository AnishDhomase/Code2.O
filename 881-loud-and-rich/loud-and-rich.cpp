class Solution {
    void bfs(vector<int> &ans, vector<vector<int>> adjList, vector<int> quiet){
        int n = quiet.size();
        queue<pair<int,int>> Q; //{node,parNode}
        for(int i=0; i<n; i++)
            Q.push({i,i});
        while(Q.size()){
            int node = Q.front().first, parNode = Q.front().second;
            Q.pop();
            for(auto adjNode : adjList[node]){
                if(quiet[parNode] < quiet[ans[adjNode]]){
                    ans[adjNode] = parNode;
                    Q.push({adjNode,parNode});
                }
            }
        }
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> ans(n);
        vector<vector<int>> adjList(n, vector<int>(0));
        for(auto e : richer){
            int high = e[0], low = e[1];
            adjList[high].push_back(low);
        }
        for(int i=0; i<n; i++)  ans[i]=i;
        bfs(ans, adjList, quiet);
        return ans;
    }
};