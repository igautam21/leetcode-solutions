class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]+1) break;
            sum+=nums[i];
        }
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mx=max(nums[i],mx);
        }
        int ans;
        for(int i=sum;i<=(mx+1);i++){
            if(find(nums.begin(), nums.end(), i) != nums.end()) continue;
            ans=i;
            break;
        }
        return ans;
    }
};