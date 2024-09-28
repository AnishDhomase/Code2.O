class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        for(auto time : times){
            int from = time[0] - 1, to = time[1] - 1;
            int wt = time[2];
            adjList[from].push_back({to,wt});
        }
        vector<int> time(n,1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHp;
        time[k-1] = 0;
        minHp.push({0,k-1});
        while(minHp.size() > 0){
            auto curr = minHp.top();
            minHp.pop();
            int currTime = curr.first, currNode = curr.second;
            if(currTime > time[currNode])   continue;
            for(auto adj : adjList[currNode]){
                int adjNode = adj.first, adjTime = adj.second;
                int timeToReach = currTime + adjTime;
                if(timeToReach < time[adjNode]){
                    time[adjNode] = timeToReach;
                    minHp.push({timeToReach,adjNode});
                }
            }
        }
        int maxTime = *max_element(time.begin(), time.end());
        return maxTime == 1e9 ? -1 : maxTime;
    }
};