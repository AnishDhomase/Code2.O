class Solution {
    int getMutatedSum(int val, vector<int> arr){
        int mutatedSum = 0;
        for(auto e : arr){
            if(e <= val)
                mutatedSum += e;
            else    mutatedSum += val;
        }
        return mutatedSum;
    }
public:
    int findBestValue(vector<int>& arr, int target) {
        int smallestDiff = 1e9, val = -1;
        int low = 0, high = *max_element(arr.begin(), arr.end());
        while(low <= high){
            int mid = low + (high-low)/2;
            int mutatedSum = getMutatedSum(mid, arr);
            int diff = abs(target - mutatedSum); 

            if(diff < smallestDiff){
                smallestDiff = diff;
                val = mid;
            }
            else if(diff == smallestDiff){
                val = min(val, mid);
            }

            if(mutatedSum >= target)
                high = mid-1;
            else if(mutatedSum < target)
                low = mid+1;
        }
        return val;
    }
};