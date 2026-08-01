class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>pair;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(nums[n-1]!=nums[n-2]) pair.push_back(nums[n-1]);
        for(int i=0;i<nums.size()-1;i+=2){
            if((nums[i]^nums[i+1])!=0){
                pair.push_back(nums[i]);
                i--;
            }
        }
        return pair;
    }
};