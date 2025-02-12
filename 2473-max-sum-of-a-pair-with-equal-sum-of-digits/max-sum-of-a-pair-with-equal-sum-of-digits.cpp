class Solution {
    int getSumOfDigits(int n){
        int digSum = 0;
        while(n > 0){
            digSum += n % 10;
            n /= 10;
        }
        return digSum;
    }
public:
    int maximumSum(vector<int>& nums) {
        int maxDigSum = -1;
        map<int, priority_queue <int, vector<int>, greater<int>>> mp;
        for(auto n: nums){
            int digSum = getSumOfDigits(n);
            if(mp[digSum].size() < 2)
                mp[digSum].push(n);
            else{
                if(mp[digSum].top() < n){
                    mp[digSum].pop();
                    mp[digSum].push(n);
                }    
            }
        }
        for(auto it: mp){
            auto minHeap = it.second;
            if(minHeap.size() == 2){
                int digSum = 0;
                while(minHeap.size() > 0){
                    digSum += minHeap.top();
                    minHeap.pop();
                }
                maxDigSum = max(maxDigSum, digSum);
            }
        }
        return maxDigSum;

    }
};