class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2,j=n-1;
        bool flag=false;
        while(i>=0){
            if(nums[i]<nums[j]) {
                flag=true;
                break;
            }
            i--,j--;
        }
        if(!flag){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int k=n-1;k>i;k--){
            if(nums[k]>nums[i]){
                swap(nums[i],nums[k]);
                break;
            }
        }
        sort(nums.begin()+i+1,nums.end());
    }
};