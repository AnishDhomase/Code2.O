class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp; //{sum, leftMostPosition}
        int n=nums.size(), sum=0, maxLen=0;

        for(int i=0; i<n; i++){
            if(nums[i]) sum ++;
            else        sum --;
            if(sum==0){  
                maxLen = i+1;
                continue;
            }
            if(mp[sum]){
                maxLen = max(maxLen, i+1 - mp[sum]);
            }
            else    mp[sum] = i+1;
        }
        return maxLen;

        // map<pair<int,int>, int> mp; //{zeroes, ones} => index+1
        // int n=nums.size(), ones=0, zeroes=0, maxLen=0;

        // for(int i=0; i<n; i++){
        //     if(nums[i]) ones ++;
        //     else        zeroes ++;

        //     if(ones == zeroes) {
        //         maxLen = i+1;
        //         mp[{zeroes,ones}] = i+1;
        //         continue;
        //     }
        //     int o=0, z=0;
        //     if(ones > zeroes)
        //         o = ones - zeroes;
        //     else
        //         z = zeroes - ones;
        //     if(mp[{z,o}])
        //         maxLen = max(maxLen, i+1 - mp[{z,o}]);
        //     mp[{zeroes,ones}] = i+1;
        // }
        // return maxLen;
    }
};