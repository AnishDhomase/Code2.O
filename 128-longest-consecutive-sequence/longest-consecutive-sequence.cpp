class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestSeq = 0;
        unordered_set<int> S;
        for(auto num : nums)
            S.insert(num);
        for(auto num : S){
            if(S.find(num-1) == S.end()){ //This is the starting point
                int start = num;
                int len = 1;
                while(S.find(start+1) != S.end()){
                    len++;
                    start++;
                }
                longestSeq = (len > longestSeq) ? len : longestSeq;
            }
        }
        return longestSeq;
    }
};