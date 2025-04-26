typedef long long LL;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        LL cnt;
        int i, j, n = nums.size();
        map<int,int> freq;
        vector<int> nextOutOfRangeInd(n,n);
        i = j = cnt = 0;
        int outOfRangeIndex = n;
        for(int i=n-1; i>=0; i--){
            nextOutOfRangeInd[i] = outOfRangeIndex;
            outOfRangeIndex = nums[i] < minK || nums[i] > maxK ? i : outOfRangeIndex;
        }
        while(j<n){
            freq[nums[j]] ++;
            auto maxIt = *freq.rbegin();
            auto minIt = *freq.begin();
            if(maxIt.first > maxK || minIt.first < minK){
                i = ++j;
                freq.clear();
                continue;
            }
            while(freq[minK] > 0 && freq[maxK] > 0){
                cnt += (LL) nextOutOfRangeInd[j] - j;
                if(--freq[nums[i]] == 0)
                    freq.erase(nums[i]);
                i++; 
            }
            j ++;
        }
        return cnt;

    }
};