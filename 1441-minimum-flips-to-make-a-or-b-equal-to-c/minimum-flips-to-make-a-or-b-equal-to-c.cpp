class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        for(int i=0; i<32; i++){
            bool isSetInA = a & 1 << i;
            bool isSetInB = b & 1 << i;
            bool isSetInC = c & 1 << i;
            if(isSetInC){
                if(!isSetInA && !isSetInB) cnt ++;
            }
            else{
                if(isSetInA) cnt ++;
                if(isSetInB) cnt ++;
            }    
        }
        return cnt;
    }
};