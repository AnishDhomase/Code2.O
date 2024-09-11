class Solution {
public:
    int minBitFlips(int start, int goal) {
        int sBitsArr[32]={0}, gBitsArr[32]={0};
        int sTemp=0, gTemp=0;
        for(int i=0; i<32; i++){
            if(sTemp == start)  break;
            else if(sTemp + pow(2,31-i) <= start){
                sTemp += pow(2,31-i);
                sBitsArr[i] = 1; 
            }
        }
        for(int i=0; i<32; i++){
            if(gTemp == goal)  break;
            else if(gTemp + pow(2,31-i) <= goal){
                gTemp += pow(2,31-i);
                gBitsArr[i] = 1; 
            }
        }
        int ct=0;
        for(int i=0; i<32; i++){
            if(sBitsArr[i] != gBitsArr[i])  ct++;
        }
        return ct;
        
    }
};