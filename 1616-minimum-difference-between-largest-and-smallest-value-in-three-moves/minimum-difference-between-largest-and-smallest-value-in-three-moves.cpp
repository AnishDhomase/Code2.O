class Solution {
    int nextLargestElem(vector<int> &nums, vector<int> &smallCopy, unordered_set<int> &st){
        int n = nums.size(), ind = -1;
        int largest = INT_MAX, smallest = INT_MIN; 
         if(smallCopy.size() > 4)
            largest = smallCopy.back();
        for(int i=0; i<n; i++){
            if(smallest <= nums[i] && nums[i] <= largest){
                if(st.find(i) == st.end()){
                    smallest = nums[i];
                    ind = i;
                }
            }
        }
        st.insert(ind);
        return nums[ind];
    }
    int nextSmallestElem(vector<int> &nums, vector<int> &smallCopy, unordered_set<int> &st){
        int n = nums.size(), ind = -1;
        int smallest = INT_MIN, largest = INT_MAX; 
        if(smallCopy.size())
            smallest = smallCopy.back();
        for(int i=0; i<n; i++){
            if(smallest <= nums[i] && nums[i] <= largest){
                if(st.find(i) == st.end()){
                    largest = nums[i];
                    ind = i;
                }
            }
        }
        st.insert(ind);
        return nums[ind];
    }
    void findMinDiff(int start, int end, int moves, long long &minDiff, vector<int> &smallCopy){
        if(moves == 3){    
            minDiff = min<long long>((long long)smallCopy[end] - (long long)smallCopy[start], minDiff);
            return;
        }
        findMinDiff(start+1, end, moves+1, minDiff, smallCopy);
        findMinDiff(start, end-1, moves+1, minDiff, smallCopy);
    }
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        long long minDiff = 1e15;
        vector<int> smallCopy;
        unordered_set<int> st;
        if(n <= 4)  return 0;
        if(n < 8){
            for(auto num: nums) smallCopy.push_back(num);
            sort(smallCopy.begin(), smallCopy.end());
        }
        else{
            for(int i=0; i<4; i++)
                smallCopy.push_back(nextSmallestElem(nums, smallCopy, st));
            for(int i=0; i<4; i++)
                smallCopy.push_back(nextLargestElem(nums, smallCopy, st));
            reverse(smallCopy.begin()+4, smallCopy.end());
        }
        findMinDiff(0, smallCopy.size()-1, 0, minDiff, smallCopy);
        return minDiff;
    }
};