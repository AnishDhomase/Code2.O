class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> freqMp;
        map<int, priority_queue<int>> mp;
        for(auto num : nums)
            freqMp[num] ++;
        for(auto it : freqMp){
            int freq = it.second, num = it.first;
            mp[freq].push(num);
        }
        for(auto it : mp){
            int freq =  it.first;
            auto maxHeap = it.second;
            while(maxHeap.size() > 0){
                int num = maxHeap.top();
                for(int i=0; i<freq; i++)
                    ans.push_back(num);
                maxHeap.pop();
            }
        }
        return ans;
        
        
    }
};