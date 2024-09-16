/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    void findInSubArray(int l, int r, MountainArray &mountainArr, int target, int &ans){
        if(l > r)   return;
        int m = l + (r-l)/2;

        int curve; //-1: inc, 0:peak, 1:dec
        int n = mountainArr.length();

        // configure is peak/inc/dec
        int beforeM = INT_MIN, M = mountainArr.get(m), afterM = INT_MIN;
        if(m-1 >= 0)
            beforeM = mountainArr.get(m-1);
        if(m+1 < n)
            afterM = mountainArr.get(m+1);
        if((beforeM < M) && (M < afterM)) curve = -1;
        else if((beforeM > M) && (M > afterM))  curve = 1;
        else curve = 0;

        if(M == target){
            ans = min(ans, m);
            if(curve == 0)   
                return;
            else if(curve == 1)
                findInSubArray(l, m-1, mountainArr, target, ans);
        }
        else if(curve == -1){
            if(target > M)
                findInSubArray(m+1, r, mountainArr, target, ans);
            else {
                findInSubArray(l, m-1, mountainArr, target, ans); //find in left
                if(ans == 1e9)
                    findInSubArray(m+1, r, mountainArr, target, ans);  //find in right // no need if in left
            }
        }
        else if(curve == 1){
            if(target > M)
                findInSubArray(l, m-1, mountainArr, target, ans);
            else {
                findInSubArray(l, m-1, mountainArr, target, ans); //find in left
                if(ans == 1e9)
                    findInSubArray(m+1, r, mountainArr, target, ans);  //find in right // no need if in left
            }
        }
        else {
            if(target > M)
                return;
            findInSubArray(l, m-1, mountainArr, target, ans); //find in left
            if(ans == 1e9)
                findInSubArray(m+1, r, mountainArr, target, ans);  //find in right // no need if in left
        }
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int ans = 1e9;
        findInSubArray(0, mountainArr.length()-1, mountainArr, target, ans);
        if(ans == 1e9)  return -1;
        return ans;
    }
};