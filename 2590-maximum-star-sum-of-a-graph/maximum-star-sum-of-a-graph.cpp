class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size(), maxSum = INT_MIN;
        vector<vector<int>> adjList(n);
        for(auto e : edges){
            int v1 = e[0], v2 = e[1];
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }
        for(int i=0; i<n; i++){
            priority_queue<int> maxHeap;
            for(auto adjNode : adjList[i])
                maxHeap.push(vals[adjNode]);
            int sum = vals[i];
            maxSum = max(sum, maxSum);
            for(int i=0; i<k && maxHeap.size()>0; i++){
                sum += maxHeap.top();
                maxSum = max(sum, maxSum);
                maxHeap.pop();
            }      
        }
        return maxSum;
    }
};