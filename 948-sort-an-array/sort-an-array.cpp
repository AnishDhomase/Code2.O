class Solution {
    int partition(vector<int> &nums, int l, int r){
        int p = l;
        bool flag = true;
        while(l < r){
            if(flag){
                if(nums[p] > nums[r]){
                    swap(nums[p],nums[r]);
                    p=r;
                    flag = false;
                }
                else    r--;
            }
            else{
                if(nums[l] > nums[p]){
                    swap(nums[p],nums[l]);
                    p=l;
                    flag = true;
                }
                else    l++;
            }
        }
        return p;
    }
    void quickSort(vector<int> &nums, int l, int r){
        if(l<r){
            int p = partition(nums,l,r);
            quickSort(nums,l,p-1);
            quickSort(nums,p+1,r);
        }
    }
    void merge(vector<int> &nums, int l, int m, int r){
        vector<int> v1, v2;
        v1.assign(nums.begin()+l, nums.begin()+m+1);
        v2.assign(nums.begin()+m+1, nums.begin()+r+1);
        int i=0, j=0, k=l, sz1=m-l+1, sz2=r-m;
        while(i<sz1 && j<sz2){
            if(v1[i]<v2[j]){
                nums[k]=v1[i];
                i++;
            }
            else{
                nums[k]=v2[j];
                j++;
            }
            k++;
        }
        while(i<sz1){
            nums[k]=v1[i];
            i++;
            k++;
        }
        while(j<sz2){
            nums[k]=v2[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int> &nums, int l, int r){
        if(l<r){
            int mid = (l+r)/2;
            mergeSort(nums,l,mid);
            mergeSort(nums,mid+1,r);
            merge(nums,l,mid,r);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};