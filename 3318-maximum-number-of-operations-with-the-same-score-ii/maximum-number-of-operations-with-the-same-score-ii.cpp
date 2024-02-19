struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;              
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};
class Solution {
    bool Front(int sum, int start, int end, vector<int>& nums) {
        int opSum = nums[start] + nums[start+1];
        bool ans = opSum==sum;
        return ans;
    }
    bool Back(int sum, int start, int end, vector<int>& nums) {
        int opSum = nums[end] + nums[end-1];
        bool ans = opSum==sum;
        return ans;
    }
    bool Both(int sum, int start, int end, vector<int>& nums) {
        int opSum = nums[start] + nums[end];
        bool ans = opSum==sum;
        return ans;
    }
    int fun(int sum, int start, int end, vector<int> nums, unordered_map<pair<int, int>, int, hash_pair> &mp){
        if(start < end){
            int way1=0, way2=0, way3=0;
            if(mp[{start,end}])
                return mp[{start,end}];
            if(Front(sum, start, end, nums)){
                way1 = 1 + fun(sum, start+2, end, nums, mp);
                if(way1 == (end-start+1)/2)
                    return mp[{start,end}] = way1;
            }
            if(Back(sum, start, end, nums)){
                way2 = 1 + fun(sum, start, end-2, nums, mp);
                if(way2 == (end-start+1)/2)
                    return mp[{start,end}] = way2;
            }
            if(Both(sum, start, end, nums)){
                way3 = 1 + fun(sum, start+1, end-1, nums, mp);
            }
            return mp[{start,end}] = max(way1, max(way2,way3));
        }
        return 0;
    }
public:
    int maxOperations(vector<int>& nums) {
        unordered_map<pair<int, int>, int, hash_pair> mp; //{{start,end},MaxSteps}
        int ct1, ct2, ct3;
        int n = nums.size();
        ct1 = 1 + fun(nums[0]+nums[1], 2, n-1, nums, mp);
        if(ct1==n/2)    return ct1;
        mp.clear();
        ct2 = 1 + fun(nums[n-1]+nums[n-2], 0, n-3, nums, mp);
        if(ct2==n/2)    return ct2;
        mp.clear();
        ct3 = 1 + fun(nums[0]+nums[n-1], 1, n-2, nums, mp);
        mp.clear();
        return max(ct1, max(ct2, ct3));
    }
};