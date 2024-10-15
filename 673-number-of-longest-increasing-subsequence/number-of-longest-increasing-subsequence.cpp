class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), longest = 0, longestCnt = 0;
        vector<int> len(n), cnt(n, 1);
        for(int i=0; i<n; i++){
            int maxL = 0, c = 1;
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    if(len[j] > maxL){
                        maxL = len[j];
                        c = cnt[j];
                    }
                    else if(len[j] == maxL){
                        c += cnt[j];
                    }
                }
            }
            len[i] = maxL + 1;
            cnt[i] = c;
        }
        longest = *max_element(len.begin(), len.end());
        for(int i=0; i<n; i++)
            if(len[i] == longest)
                longestCnt += cnt[i];
        return longestCnt;
    }
};