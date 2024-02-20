class Solution {
public:
    int getElem(int i,int j,vector<int>& nums)
    {
        if(i==j)
        {
            int k = nums.size();
            if(nums[i]==k)  return k-1;
            else return k;
        }
        else if(i+1==j)
        {
            if(nums[i]!=i) return i;
            else return j;
        }
        else{
            int m=(i+j)/2;
            if(nums[m] != m)
                getElem(i,m,nums);
            else    getElem(m+1,j,nums);
        }
        return 110;
    }

    int missingNumber(vector<int>& nums) {
        int xor1=0, xor2=0;
        int n = nums.size();
        for(int i=0; i<=n; i++){
            if(i<n){
                xor1 ^= nums[i]; 
            }
            xor2 ^= i; 
        }
        return xor1 ^ xor2;


        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // return getElem(0,n-1,nums);
        /*int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n==0)
            return 0;
        for(int i=0; i<=n; i++)
        {
            if(i==n)    return i;
            else if(nums[i] != i)   return i;
        } 
        return -1;
        */
    }
};