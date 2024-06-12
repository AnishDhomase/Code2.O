class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero=0,two=n-1;
        vector<int> v(n,1);
        for(auto x:nums)
        {
            if(x==0)
                {v[zero]=0; zero++;}
            else if(x==2)
                {v[two]=2; two--;}
        }
        nums=v;
    }
};