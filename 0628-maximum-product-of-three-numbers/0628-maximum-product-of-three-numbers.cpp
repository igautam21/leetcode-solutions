class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int ans;
        int p=nums[1]*nums[2];
        int n=nums.size();
        int q=nums[n-1]*nums[n-2];
        if(p>q){
            ans = p*nums[0];
        }
        else{
            ans = q*nums[0];
        }
        int r=nums[0]*nums[1]*nums[2];
        return max(ans,r);
    }
};