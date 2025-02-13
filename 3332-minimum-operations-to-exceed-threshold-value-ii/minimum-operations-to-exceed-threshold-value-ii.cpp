typedef long long LL;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ops = 0;
        priority_queue<LL, vector<LL>, greater<LL>> minHeap;
        for(auto num: nums) minHeap.push(num);
        while(minHeap.size() >= 2){
            LL x = minHeap.top();
            if(x >= k)  break;
            minHeap.pop();
            LL y = minHeap.top();
            minHeap.pop();
            LL newVal = (LL) min(x,y) * 2 + max(x,y);
            minHeap.push(newVal);
            ops ++;
        }
        return ops;
    }
};