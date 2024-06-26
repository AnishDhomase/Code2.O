class Solution {
    void merge(int l, int mid, int r, vector<int> &nums){
        vector<int> mergedArr;
        int left=l, right=mid+1;
        while(left <= mid && right <= r){
            if(nums[left] < nums[right]){
                mergedArr.push_back(nums[left]);
                left ++;
            }
            else{
                mergedArr.push_back(nums[right]);
                right ++;
            }
        }
        while(left <= mid){
            mergedArr.push_back(nums[left]);
            left ++;
        }
        while(right <= r){
            mergedArr.push_back(nums[right]);
            right ++;
        }
        for(int i=l; i<=r; i++){
            nums[i] = mergedArr[i-l];
        }
    }
    int countRevPairs(int l, int mid, int r, vector<int> &nums){
        int left=l, right=mid+1, cnt=0;
        while(left <= mid && right <= r){
            if((long long)nums[left] > ((long long)2 * nums[right]))    right++;
            else{
                cnt += (right - (mid+1));
                left ++;
            }
        }
        while(left <= mid){
            cnt += (right - (mid+1));
            left ++;
        }
        return cnt;
    }
    int modMergeSort(int l, int r, vector<int> &nums){
        if(l == r)    return 0;
        int cnt = 0, mid = (l+r)/2;
        cnt += modMergeSort(l, mid, nums);
        cnt += modMergeSort(mid+1, r, nums);
        cnt += countRevPairs(l, mid, r, nums);
        merge(l, mid, r, nums);
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return modMergeSort(0, n-1, nums);
    }
};