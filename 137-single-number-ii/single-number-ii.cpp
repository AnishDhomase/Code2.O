class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitArr(32,0);
        for(auto e : nums){
            for(int i=0; i<32; i++){
                if(e & 1<<i)
                    bitArr[i]++;
            }
        }
        int singleNum = 0;
        for(int i=0; i<32; i++){
            if(bitArr[i]%3){
                singleNum += 1<<i;
            }
        }
        return singleNum;
    }
};