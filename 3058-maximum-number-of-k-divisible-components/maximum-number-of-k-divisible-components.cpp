class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int components = 0;
        vector<unordered_set<int>> adjList(n);
        queue<int> q;
        vector<long long> vals(values.begin(), values.end());
        for(auto edge: edges){
            adjList[edge[0]].insert(edge[1]);
            adjList[edge[1]].insert(edge[0]);
        }
        for(int i=0; i<n; i++)
            if(adjList[i].size() == 1)  q.push(i);
        while(q.size() > 0){
            // get Leaf
            int leafNode = q.front();
            q.pop();

            // edge case for single node
            if(adjList[leafNode].size() == 0) break;

            // romove edge
            int otherEndNode = *((adjList[leafNode]).begin());
            adjList[leafNode].clear();
            adjList[otherEndNode].erase(leafNode);
            if(adjList[otherEndNode].size() == 1)  q.push(otherEndNode);

            // Result of merge or separate
            if(vals[leafNode] % k == 0)   components ++;                   
            else    vals[otherEndNode] = ((long long) vals[otherEndNode] + vals[leafNode]);
        }
        return components + 1;

    }
};