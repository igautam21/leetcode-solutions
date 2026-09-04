class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            int mx=INT_MIN,mn=INT_MAX;
            for(int j=0;j<=i;j++){
                mx=max(mx,nums[j]);
            }
            for(int j=i;j<nums.size();j++){
                mn=min(mn,nums[j]);
            }
            if((mx-mn)<=k) return i;
        }
        return -1;
    }
};