class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int> > pq;
        for(auto e : nums)
            pq.push(e);
        while(k > 0){
            k--;
            int min = pq.top();
            pq.pop();
            pq.push(min + 1);
        }
        long long prod = 1;
        while(pq.size() && prod>0){
            prod = (prod * pq.top()) % mod;
            pq.pop();
        }
        return prod;
        
    }
};