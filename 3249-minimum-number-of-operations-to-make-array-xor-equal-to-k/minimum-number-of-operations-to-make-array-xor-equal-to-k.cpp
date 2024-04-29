class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for (auto& x : nums) {
            ans = ans ^ x;
        }
        ans = ans ^ k;
        int res = 0;
        while (ans > 0) {
            if (ans & 1)
                res++;
            ans = ans >> 1;
        }
        return res;
        // int xr = k;
        // for(int e : nums)
        //     xr ^= e;
        // int ops = 0;
        // for(int i=0; i<32; i++)
        //     if(xr && (1<<i)){  ops++;}
        // return ops;
    }
};