class Solution {
    // int getValids(int i, int j, vector<int> nums, unordered_map<int,int> freq, map<pair<int,int>,int> &mp, int k){
    //     int ct = 0;
    //     while(freq.size() == k){
    //         if(!mp[{i,j}]){
    //             mp[{i,j}]++;
    //             ct++;
    //         }
    //         freq[nums[i]]--;
    //         if(freq[nums[i]]==0)
    //             freq.erase(nums[i]);
    //         i++;
    //     }
    //     return ct;
    // }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ctk=0, ctk_1=0, n = nums.size();
        int i=0, j=0;
        unordered_map<int,int> freqk, freqk_1;
        while(i<n && j<n){
            freqk[nums[j]]++;
            if(freqk.size() <= k){
                ctk += j-i+1;
                j++;
            }
            else{
                while(freqk.size() > k){
                    freqk[nums[i]]--;
                    if(freqk[nums[i]]==0)
                        freqk.erase(nums[i]);
                    i++;
                }
                freqk[nums[j]]--;
            }
        }
        i=0; j=0;
        if(k-1)
        while(i<n && j<n){
            freqk_1[nums[j]]++;
            if(freqk_1.size() <= k-1){
                ctk_1 += j-i+1;
                j++;
            }
            else{
                while(freqk_1.size() > k-1){
                    freqk_1[nums[i]]--;
                    if(freqk_1[nums[i]]==0)
                        freqk_1.erase(nums[i]);
                    i++;
                }
                freqk_1[nums[j]]--;
            }
        }
        return ctk - ctk_1;


        // TLE
        // int ct=0, n = nums.size();
        // int i=0, j=0;
        // map<pair<int,int>,int> mp;
        // unordered_map<int,int> freq;
        // while(i<n && j<n){
        //     freq[nums[j]]++;
        //     if(freq.size() == k){
        //         ct += getValids(i, j, nums, freq, mp, k);
        //         j++;
        //     }
        //     else if(freq.size() < k){
        //         j++;
        //     }
        //     else{
        //         while(freq.size() > k){
        //             freq[nums[i]]--;
        //             if(freq[nums[i]]==0)
        //                 freq.erase(nums[i]);
        //             i++;
        //         }
        //         freq[nums[j]]--;
        //     }
        // }
        // return ct;


        // TLE
        // int ct=0;
        // int n = nums.size();
        // vector<pair<int,int>> v;
        // int i=0, j=0;
        // unordered_map<int,int> freq;
        // while(j<n){
        //     freq[nums[j]]++;
        //     if(freq.size()==k+1){
        //         v.push_back({i,j-1});
        //         while(freq.size()!=k){
        //             freq[nums[i]]--;
        //             if(freq[nums[i]]==0)
        //                 freq.erase(nums[i]);
        //             i++;
        //         }
        //     }
        //     j++;
        // }
        // if(freq.size()==k){
        //     v.push_back({i,j-1});
        // }
        // for(auto e : v){
        //     i=e.first, j=i, n=e.second;
        //     unordered_map<int,int> freq1;
        //     while(i<=n && j<=n){
        //         if(i>j) j=i;
        //         freq1[nums[j]]++;
        //         if(freq1.size()==k){
        //             ct += n-j+1;
        //             if(freq1[nums[i]])
        //                 freq1[nums[i]]--;
        //             if(freq1[nums[i]]==0)
        //                 freq1.erase(nums[i]);
        //             if(freq1[nums[j]])
        //                 freq1[nums[j]]--;
        //             if(freq1[nums[j]]==0)
        //                 freq1.erase(nums[j]);
        //             i++;
        //             j--;
        //         }
        //         j++;
        //     }
        // }
        // return ct;



        // O(n^2) TLE
        // int ct=0;
        // int n = nums.size();
        // for(int i=0; i<n; i++){
        //     unordered_map<int,int> freq;
        //     int uniq;
        //     for(int j=i; j<n; j++){
        //         freq[nums[j]]++;
        //         uniq = freq.size();
        //         if(uniq == k)   ct++;
        //         else if(uniq > k) break;
        //     }
        //     freq[nums[i]]--;
        //     uniq = freq.size();
        //     if(uniq < k)
        //         break;
        // }
        // return ct;
    }
};