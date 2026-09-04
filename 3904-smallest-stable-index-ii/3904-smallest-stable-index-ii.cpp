class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>premx(nums.size());
        vector<int>postmn(nums.size());
        premx[0]=nums[0];
        postmn[n-1]=nums[n-1];
        for(int i=1;i<nums.size();i++){
            premx[i]=max(nums[i],premx[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            postmn[i]=min(nums[i],postmn[i+1]);
        }
        for(int i=0;i<nums.size();i++){
            if((premx[i]-postmn[i])<=k) return i;
        }
        return -1;
    }
};