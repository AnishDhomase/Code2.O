class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int totalXor = 0, i;
        for(auto e : nums)
            totalXor ^= e;
        for(i=0; i<32; i++){
            if(totalXor & 1<<i)
                break;
        }
        int n1=0, n2=0;
        for(auto e : nums){
            if(e & 1<<i)
                n1 ^= e;
            else
                n2 ^= e; 
        }
        return {n1,n2};
    }
};