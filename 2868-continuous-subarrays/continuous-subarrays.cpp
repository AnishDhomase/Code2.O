class Solution {
    bool isMaxDiffSmallerThan3(multiset<int> &st){
        if(st.size() <= 1)  return true;
        int low = *(st.begin()), high = *(st.rbegin());
        return ((high - low) < 3);
    }
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long cnt = 0;
        int i=0, j=1, n=nums.size(), lastBoundary=0;
        multiset<int> st={nums[0]};
        while(j<n){
            st.insert(nums[j]);
            if(isMaxDiffSmallerThan3(st))   j++;
            else{
                lastBoundary = j-1;
                int sizeOfSubarr = j-i;
                cnt = (long long) cnt + (long long) sizeOfSubarr * (sizeOfSubarr + 1)/2;
                while(!isMaxDiffSmallerThan3(st)){
                    st.erase(st.find(nums[i]));
                    i++;
                }
                if(i <= lastBoundary){
                    int overlappedSubarrSz = lastBoundary - i + 1;
                    cnt -= overlappedSubarrSz * (overlappedSubarrSz + 1)/2;
                }
                j ++;
            }
        }
        int sizeOfSubarr = j-i;
        cnt = (long long) cnt + (long long) sizeOfSubarr * (sizeOfSubarr + 1)/2;
        return cnt;
    }
};