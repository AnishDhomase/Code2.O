class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        while(i<m && j<n){
            if(nums1[i] <= nums2[j])    i++;
            else{
                swap(nums1[i], nums2[j]);
                int k=0;
                while(k+1 < n && nums2[k] > nums2[k+1]){
                    swap(nums2[k], nums2[k+1]);
                    k++;
                }
            }
        }
        i=m;
        j=0;
        while(j<n){
            nums1[i] = nums2[j];
            i++;
            j++;
        }
    }
};