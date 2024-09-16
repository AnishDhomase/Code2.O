class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high) / 2;
            int misssingCnt = arr[mid] - mid - 1;
            if(misssingCnt < k) low = mid+1;
            else                high = mid-1;
        }
        if(high != -1){
            int afterThis = k - (arr[high] - high - 1);
            return arr[high] + afterThis;
        }
        int beforeThis = (arr[low] - low - 1) - (k-1);
        return arr[low] - beforeThis;
    }
};