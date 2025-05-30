class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> heap;
        for(int i=0; i<k; i++)  heap.push({nums[i], i});
        vector<int> ans = { heap.top().first };

        for(int i=k; i<n; i++){
            heap.push({nums[i], i});
            while(heap.top().second <= i-k) heap.pop();
            ans.push_back(heap.top().first);
        }
        return ans;
    }
};