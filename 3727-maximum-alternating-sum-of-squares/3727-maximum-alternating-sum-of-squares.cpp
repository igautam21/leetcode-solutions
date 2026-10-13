class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.rbegin(),nums.rend());
        long long ans=0;
        if(n%2!=0){
            for(int i=0;i<n;i++){
                if(i<=n/2)
                    ans+=nums[i];
                else
                    ans-=nums[i];
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(i<n/2)
                    ans+=nums[i];
                else
                    ans-=nums[i];
            }
        }
        return ans;
    }
};