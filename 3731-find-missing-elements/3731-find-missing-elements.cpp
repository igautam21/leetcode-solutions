class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int low=nums[0],high=nums[nums.size()-1];
        vector<int>ans;
        for(int i=low+1;i<high;i++){
            if(find(nums.begin(), nums.end(), i) != nums.end()) continue;
            else ans.push_back(i);
        }
        return ans;
    }
};