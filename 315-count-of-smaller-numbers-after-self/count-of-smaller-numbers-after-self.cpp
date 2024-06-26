class Solution {
    void merge(int l, int mid, int r, vector<pair<int,int>> &numsWithind, vector<int> &counts){
        int left = l, right = mid + 1;
        vector<pair<int,int>> mergedArr;
        while(left <= mid && right <= r){
            if(numsWithind[left].first > numsWithind[right].first){
                mergedArr.push_back(numsWithind[right]);
                right++;
            }
            else{
                mergedArr.push_back(numsWithind[left]);
                counts[numsWithind[left].second] += (right - (mid+1));
                left++;
            }
        }
        while(right <= r){
            mergedArr.push_back(numsWithind[right]);
            right++;
        }
        while(left <= mid){
            mergedArr.push_back(numsWithind[left]);
            counts[numsWithind[left].second] += (right - (mid+1));
            left++;
        }
        for(int i=l; i<=r; i++){
            numsWithind[i] = mergedArr[i-l];
        }

    }
    void modMergeSort(int l, int r, vector<pair<int,int>> &numsWithind, vector<int> &counts){
        int mid = (l+r)/2;
        if(l < mid) modMergeSort(l, mid, numsWithind, counts);
        if(mid+1 < r) modMergeSort(mid+1, r, numsWithind, counts);
        merge(l, mid, r, numsWithind, counts);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n,0);
        if(n <= 1)  return counts;
        vector<pair<int,int>> numsWithind;
        for(int i=0; i<n; i++)
            numsWithind.push_back({nums[i], i});
        modMergeSort(0, n-1, numsWithind, counts);
        return counts;
    }
};