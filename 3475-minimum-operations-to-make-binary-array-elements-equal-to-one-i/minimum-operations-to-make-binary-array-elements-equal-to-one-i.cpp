class Solution {
    void flipFromI(int i, vector<int>& modNums){
        modNums[i] = !modNums[i];
        modNums[i+1] = !modNums[i+1];
        modNums[i+2] = !modNums[i+2];
    }
public:
    int minOperations(vector<int>& nums) {
        vector<int> modNums = nums;
        int n = nums.size(), cnt = 0;
        for(int i=0; i<n; i++){
            if(modNums[i] == 0){
                if(i+2 >= n) return -1;
                flipFromI(i, modNums);
                cnt ++;
            }
        }
        return cnt;
    }
};