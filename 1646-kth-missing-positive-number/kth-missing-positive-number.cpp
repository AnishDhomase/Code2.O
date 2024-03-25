class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 1, high = n+k;
        while(low <= high){
            int mid = low + (high-low)/2;
            int lb = lower_bound(arr.begin(), arr.end(), mid) - arr.begin();
            int leftMissingCt;
            if(lb<n && arr[lb] == mid)
                leftMissingCt = mid - (lb+1);
            else 
                leftMissingCt = mid - lb;
            if(leftMissingCt == k){
                if(lb==n || arr[lb] != mid)
                    return mid;
                else    high = mid - 1;
            }
            else if(leftMissingCt < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};