class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        vector<int> vis(n,0);
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(int i=0; i<n; i++)  minHeap.push({nums[i],i});
        while(minHeap.size() > 0){
            auto minElem = minHeap.top();
            int val = minElem.first, ind = minElem.second;
            minHeap.pop();
            if(vis[ind] == 1)   continue;
            else                score = (long long) score + val; 
            vis[ind] = 1;
            if(ind-1 >= 0)  vis[ind-1] = 1;
            if(ind+1 < n)   vis[ind+1] = 1;
        }
        return score;

    }
};